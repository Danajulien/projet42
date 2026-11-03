#include <stdlib.h>
#include <stdio.h>

typedef struct s_player
{
    char    *name;
    int     score;
    int     energy;
}   t_player;

int ft_strlen(char *s)
{
    if(s == NULL)
        return 0;
    int len = 0;
    while(s[len])
    {
        len++;
    }
    return len;
}

char *ft_clone(char *src)
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

void     ft_free_team(t_player *team, int count)
{
    if(count == 0 || team == NULL)
    {
        free(team);
        return;
    }
    for(int i = 0; i < count; i++)
    {
        free(team[i].name);
    }
    free(team);
}

t_player *ft_clone_team(t_player *players, int count)
{
    if (players == NULL)
        return NULL;
    t_player *cloned_team = malloc(count * sizeof(t_player));
    if (cloned_team == NULL)
        return NULL;
    for(int i = 0; i < count; i++)
    {
        cloned_team[i].name = ft_clone(players[i].name);
        if(cloned_team[i].name == NULL)
        {
            ft_free_team(cloned_team, i);
            return NULL;
        }
        cloned_team[i].score = players[i].score;
        cloned_team[i].energy = players[i].energy;
    }
    return cloned_team;
}
