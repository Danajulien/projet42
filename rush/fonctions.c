/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 14:41:31 by legiacal          #+#    #+#             */
/*   Updated: 2026/10/11 15:05:09 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// int		main(int argc, char **argc)
// {
// 	return 0;
// }
