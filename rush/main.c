
#include <unistd.h>
void    ft_putstr(char* str, int n);
int	is_argument_good_format(char *str, int *tab_arg);


int main(int argc, char** argv)
{
    if (argc != 2)
    {
        ft_putstr("Mauvais nombre d'arguments", 1);
        return 1;
    }
    int tab_arg[16];
    if (is_argument_good_format(argv[1], tab_arg) != 1)
    {
        ft_putstr("mauvais format d'input ou solution impossible", 1);
        return 1;
    }
    ft_putstr("l'argument est valide et possede une solution", 1);
    return 0;

}