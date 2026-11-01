#include <stddef.h>
#include <stdio.h>

typedef struct s_player
{
	char	*name;
	int		score;
	int		energy;
}	t_player;

/*
parcourir le tableau players
regarder si le player en question a une energie superieur à min_energy
si oui, le prendre en compte dans la comparaison du meilleur score
si le score de celui ci est plus haut que le score max actuel, on met à jour l'adresse qu'on va return, et le max
*/
t_player	*ft_select_player(t_player *players, int count, int min_energy)
{
    if (players == NULL || count <= 0)
        return NULL;
    t_player *selected_player = NULL;
    int max_score = 0;
    for(int i = 0; i < count; i++)
    {
        if(players[i].energy >= min_energy && (players[i].score > max_score || selected_player == NULL))
        {
            max_score = players[i].score;
            selected_player = players + i;
        }
    }
    return selected_player;
}

int main(void)
{
    t_player	players[] = {
	{"Ada", 40, 8},
	{"Linus", 70, 3},
	{"Grace", 55, 6}
    };
    printf("%d", ft_select_player(players, 3, 10)->score );
}