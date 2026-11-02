#include <stddef.h>

typedef struct s_player
{
    char    *name;
    int     score;
    int     energy;
}   t_player;

int ft_remove_player(t_player *players, int *count, int index)
{
    if(players == NULL || count == NULL || *count <= 0 || index >= *count)
        return 0;
    (*count)--;
    for(int i = index; i < *count; i++)
    {
        players[i] = players[i+1];
    }
    return 1;
}
