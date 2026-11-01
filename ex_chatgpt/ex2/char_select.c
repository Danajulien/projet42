#include <stdio.h>
#include <stdlib.h>

typedef struct s_player
{
    char    *name;
    int     score;
    int     energy;
}   t_player;

t_player *ft_build_team(t_player *players, int count, int min_energy, int *team_count)
{
    if(team_count)
        *team_count = 0;
    if(players == NULL || count == 0 ||team_count == NULL)
        return NULL;

    for(int i = 0; i < count; i++)
    {
        if(players[i].energy >= min_energy)
            (*team_count)++;
    }
    t_player *team = malloc(*team_count * sizeof(t_player));
    if(team == NULL)
    {
        *team_count = 0;
        return NULL;
    }
    int i_t = 0;
    for(int i_p = 0; i_p < count; i_p++)
    {
        if(players[i_p].energy >= min_energy)
        {
            team[i_t].name = players[i_p].name;
            team[i_t].score = players[i_p].score;
            team[i_t].energy = players[i_p].energy;
            i_t++;
        }
    }
    return team;
}