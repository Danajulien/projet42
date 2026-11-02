#include <stddef.h>
#include <stdio.h>

typedef struct s_player
{
    char    *name;
    int     score;
    int     energy;
}   t_player;

int ft_add_ranked_player(t_player *players, int *count,
                        int capacity, t_player new_player)
{
    if(players == NULL || count == NULL || *count < 0 ||*count >= capacity)
    {
        return 0;
    }
    t_player temp_player = new_player;
    for(int i = 0; i < *count; i++)
    {
        if(new_player.score > players[i].score)
        {
            temp_player = players[i];
            //on copie la fin du tableau en le décalant
            while(i < *count)
            {
                players[i] = new_player;
                new_player = temp_player;
                i++;
            }
        }
    }
    (*count)++;
    players[*count - 1] = new_player;
    return 1;
}

// int main(void)
// {
//     t_player players[8] =
//     {
//         {"arria", 50, 2},
//         {"tom", 45, 5}
//     };
//     int count = 2;
//     printf("test");
//     t_player new_player = {"jerry", 48, 10};
//     if (ft_add_ranked_player(players, &count, 8, new_player))
//     {
//         for(int i = 0; i < count; i++)
//         {
//             printf("%s", players[i].name);
        
//         }
    
//     }
// }
int main(void)
{
    t_player players[3];
int count = 0;
t_player new_player = {"Niels", 40, 6};

if (ft_add_ranked_player(players, &count, 3, new_player))
    {
        for(int i = 0; i < count; i++)
        {
            printf("%s", players[i].name);
        
        }
    
    }
}