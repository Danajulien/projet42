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

t_player_node *ft_team_to_list(t_player *players, int count)
{
    t_player_node *head = malloc(sizeof(t_player_node));
    if (head == NULL)
        return NULL;
    head->player = players[0];
    head->next = NULL;

    t_player *act_player = malloc(sizeof(t_player));
    if (act_player == NULL)
        return NULL;
    act_player = head;

    for(int i = 1; i < count; i++)
    {
        t_player new_player = malloc(sizeof(t_player));
        if (new_player == NULL)
            return NULL;
        new_player.name = ft_cpy_str(players[i].name);
        new_player.score = players[i].score;
        new_player.score
    }
}


void          ft_free_player_list(t_player_node *head)
{

}