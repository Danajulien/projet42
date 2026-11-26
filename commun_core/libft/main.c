#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** Compilation independante des autres fonctions de la libft :
** cc -Wall -Wextra -Werror -g main.c ft_lstdelone.c -o test_lstdelone
** ./test_lstdelone
** valgrind --leak-check=full --show-leak-kinds=all \
**     --errors-for-leak-kinds=all --error-exitcode=2 ./test_lstdelone
**
** Les callbacks verifient le nombre d'appels et l'adresse recue.
** Valgrind verifie les free, les acces invalides et les fuites de memoire.
** Aucun maillon libere n'est relu. Les maillons sont toujours alloues.
** Les tests NULL pour lst/del verifient un comportement defensif : retour
** sans action. Ils sont distincts des appels avec un callback valide.
*/

typedef struct s_payload
{
	char	*text;
	int		*number;
}	t_payload;

static int		g_tests;
static int		g_failures;
static int		g_calls;
static int		g_correct_argument;
static void		*g_expected;

static void	*allocate(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		perror("malloc du programme de test");
		exit(2);
	}
	return (ptr);
}

static t_list	*make_node(void *content)
{
	t_list	*node;

	node = allocate(sizeof(*node));
	node->content = content;
	node->next = NULL;
	return (node);
}

static char	*copy_text(const char *text)
{
	char	*copy;

	copy = allocate(strlen(text) + 1);
	strcpy(copy, text);
	return (copy);
}

static int	*copy_number(int value)
{
	int	*copy;

	copy = allocate(sizeof(*copy));
	*copy = value;
	return (copy);
}

static void	begin_test(const char *name, void *expected)
{
	g_tests++;
	g_calls = 0;
	g_correct_argument = 1;
	g_expected = expected;
	printf("%02d. %s : ", g_tests, name);
}

static void	finish_test(int success)
{
	/* Ne pas conserver l'adresse d'un contenu potentiellement libere. */
	g_expected = NULL;
	if (success)
		printf("[OK]\n");
	else
	{
		printf("[KO] (appels de del : %d)\n", g_calls);
		g_failures++;
	}
}

static void	del_observe(void *content)
{
	g_calls++;
	if (content != g_expected)
		g_correct_argument = 0;
}

static void	del_free(void *content)
{
	del_observe(content);
	free(content);
}

static void	del_payload(void *content)
{
	t_payload	*payload;

	del_observe(content);
	payload = content;
	if (payload != NULL)
	{
		free(payload->text);
		free(payload->number);
		free(payload);
	}
}

static void	test_one(const char *name, void *content, void (*del)(void *))
{
	t_list	*node;

	node = make_node(content);
	begin_test(name, content);
	ft_lstdelone(node, del);
	/* node est maintenant invalide : on ne le dereference plus. */
	finish_test(g_calls == 1 && g_correct_argument);
}

static void	test_null_list(void)
{
	begin_test("lst NULL, callback valide : aucun appel", NULL);
	ft_lstdelone(NULL, del_free);
	finish_test(g_calls == 0);
	begin_test("lst NULL et del NULL : aucun crash", NULL);
	ft_lstdelone(NULL, NULL);
	finish_test(g_calls == 0);
}

static void	test_nested_content(void)
{
	t_payload	*payload;

	payload = allocate(sizeof(*payload));
	payload->text = copy_text("contenu compose");
	payload->number = copy_number(42);
	test_one("contenu avec allocations internes, del personnalise",
		payload, del_payload);
}

static void	test_position(int position, const char *name)
{
	t_list	*nodes[3];
	t_list	*head;
	t_list	*cursor;
	t_list	*next;
	int		i;
	int		intact;

	i = -1;
	while (++i < 3)
		nodes[i] = make_node(copy_number(10 + i));
	nodes[0]->next = nodes[1];
	nodes[1]->next = nodes[2];
	head = nodes[0];
	/* Le code appelant doit detacher le maillon de la liste. */
	if (position == 0)
		head = nodes[0]->next;
	else
		nodes[position - 1]->next = nodes[position]->next;
	begin_test(name, nodes[position]->content);
	/* On conserve le next du maillon cible pour tester sa non-suppression. */
	ft_lstdelone(nodes[position], del_free);
	cursor = head;
	intact = 1;
	i = -1;
	while (++i < 3)
	{
		if (i == position)
			continue;
		if (cursor != nodes[i])
		{
			intact = 0;
			break;
		}
		if (cursor->content == NULL || *(int *)cursor->content != 10 + i)
			intact = 0;
		cursor = cursor->next;
	}
	finish_test(intact && cursor == NULL && g_calls == 1
		&& g_correct_argument);
	/* Nettoyage independant des autres fonctions de la libft. */
	cursor = head;
	while (cursor != NULL)
	{
		next = cursor->next;
		free(cursor->content);
		free(cursor);
		cursor = next;
	}
}

static void	test_null_callback(void)
{
	t_list	*node;
	t_list	*next;
	int		*content;
	int		value;

	value = 99;
	content = copy_number(42);
	next = make_node(&value);
	node = make_node(content);
	node->next = next;
	begin_test("del NULL : maillon, contenu et suivant conserves", content);
	ft_lstdelone(node, NULL);
	finish_test(node->content == content && *content == 42
		&& node->next == next && next->content == &value
		&& value == 99 && next->next == NULL);
	/* Le retour sans action laisse le nettoyage a l'appelant. */
	free(content);
	free(node);
	free(next);
}

int	main(void)
{
	static char	static_content[] = "contenu statique";
	int			local_content;

	/* Afficher le test en cours meme si une implementation plante. */
	setvbuf(stdout, NULL, _IONBF, 0);
	local_content = 42;
	test_null_list();
	test_one("maillon seul, chaine allouee", copy_text("bonjour"), del_free);
	test_one("chaine vide allouee", copy_text(""), del_free);
	test_one("entier alloue", copy_number(-42), del_free);
	test_one("content NULL : del doit recevoir NULL une fois", NULL, del_free);
	test_one("contenu sur la pile, callback sans free", &local_content,
		del_observe);
	test_one("contenu statique, callback sans free", static_content,
		del_observe);
	test_nested_content();
	test_position(0, "suppression en tete : les deux suivants restent valides");
	test_position(1, "suppression au milieu : les voisins restent valides");
	test_position(2, "suppression en fin : les precedents restent valides");
	test_null_callback();
	printf("\nResultat : %d/%d tests reussis.\n",
		g_tests - g_failures, g_tests);
	printf("Verifier aussi la memoire avec Valgrind (commande en haut du fichier).\n");
	return (g_failures != 0);
}
