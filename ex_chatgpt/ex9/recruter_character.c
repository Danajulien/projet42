#include <stdlib.h>
#include <stdio.h>

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
    for(t_player_node *current = *head, *next = (*head)->next;
        current->next != NULL; current = current->next)
        {
            printf("%s", current->name);
        }
        return 1;
}

int main(void)
{
    

    t_player players[3] = {
        {"othilie", 50, 18},
        {"john", 60, 50},
        {"greg", 65, 55}
    }
    t_player_node *greg = {players[2], NULL};
    t_player_node *john = {players[1], greg};
    t_player_node *head = {players[0], john};
    ft_take_player(head, 10, out);
}