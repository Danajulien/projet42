/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legiacal <legiacal@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 14:41:31 by legiacal          #+#    #+#             */
/*   Updated: 2026/10/10 14:41:37 by legiacal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putstr(char* str, int n)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, str + i, 1);
        i++;
    }
    if (n == 1)
        write(1, "\n", 1);
}

void display (int argc, int *tab_soluce)
{
	int i;
	int k;

	i = 0;
	k = 1;
}

// int		main(int argc, char **argc)
// {
// 	return 0;
// }
