#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char* str)
{
    if (str == NULL)
        return 0;
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}

char *ft_cpy_str(char *src)
{
    int len = ft_strlen(src);
    char *copy = malloc((len + 1) * sizeof(char));
    if(copy == NULL)
        return NULL;
    for(int i = 0; i < len; i++)
    {
        copy[i] = src[i];

    }
    copy[len] = '\0';
    return copy;
}

typedef struct s_player
{
    char    *name;
    int     score;
    int     energy;
}   t_player;

typedef struct s_player_node
{
    t_player                player;
    struct s_player_node    *next;
}   t_player_node;

int ft_take_player(t_player_node **head, int min_energy, t_player *out)
{
    if(head == NULL || out == NULL)
        return 0;
    t_player_node *before = *head;
    for(t_player_node *current = *head;
        current != NULL; current = current->next)
        {
           if(current->player.energy >= min_energy)
           {
            //je dois retirer de la liste la node de ce player, et mettre ce player dans out
            out->name = ft_cpy_str(current->player.name);
            if (out->name == NULL)
                return 0;
            out->energy = current->player.energy;
            out->score = current->player.score;
            //t_player_node *temp = current;
            printf("1");
            before->next = current->next;
            return 1;
           }
           before = current;
        }
        return 1;
}

int main(void)
{
    t_player players[3] = {
        {"othilie", 70, 18},
        {"john", 60, 50},
        {"greg", 65, 55}
    };
    t_player out;
    t_player_node *greg = malloc(sizeof(t_player_node));
    greg->player = players[2];
    greg->next = NULL;
    t_player_node *john = malloc(sizeof(t_player_node));
    john->player = players[1];
    john->next = greg;
    t_player_node *othilie = malloc(sizeof(t_player_node));
    othilie->player = players[0]; 
    othilie->next = john;
    t_player_node *head = othilie;

    ft_take_player(&head, 17, &out);
    for(t_player_node *current = head;
        current != NULL; current = current->next)
        {
            printf("%s", current->player.name);
        }
}