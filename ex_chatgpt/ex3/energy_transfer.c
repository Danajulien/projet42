#include <stddef.h>

typedef struct s_player
{
    char    *name;
    int     score;
    int     energy;
}   t_player;

int ft_transfer_energy(t_player *from, t_player *to, int amount)
{
    if (from == NULL || to == NULL || from == to || amount <= 0)
        return (0);
    if (from->energy < amount)
        return (0);
        
    from->energy -= amount;//cette ligne doit etre apres le if sinon si l'energy du receveur dépasse 100, on aura modifié l'energie du donneur pour rien
    if (to->energy + amount > 100)
        return (0);
    to->energy += amount;
    return (1);
}