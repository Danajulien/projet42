/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:33:29 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/13 00:56:50 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *str)//sert aussi a savoir quel chiffre est un char dans sa base
{
    int	i;

	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int is_num_number_of(char c, char *str)
{
	int	i;
	int size_number;

	i = 0;
	size_number = ft_strlen(str);
	while(str[i] != c)
	{
		i++;
	}
	return (i);
}

int	to_power(int num, int power)
{
	int i;
	
	i = num;
	if (power == 0)
		return (1);
	i *= to_power(i, power - 1);
	
	return (i);
}

// char *ft_convert_base(char *nbr, char *base_from, char *base_to)
// {
//     int size_base_from;
// 	int	size_base_to;
// 	int i;
// 	int	base_in_int;
	
// 	size_base_from = ft_strlen(base_from, '\0');
// 	size_base_to = ft_strlen(base_to, '\0');
// 	i = 0;
// 	base_in_int = 0;
// 	while(nbr[i] != '\0')
// 	{
// 		base_in_int += pft_strlen(base_from, str[i]) * (to_power(ft_strlen(base_from, '\0'), ft_strlen(nbr, nbr[i])));
// 	}
// 	return base_in_int;
// }

int ft_convert_to_int(char *nbr, char *base_from)
{
    int size_base_from;
	int i;
	int	base_in_int;
	int size_number;
	
	size_base_from = ft_strlen(base_from);
	size_number = ft_strlen(nbr);
	i = 0;
	base_in_int = 0;
	while(nbr[size_number - i - 1] != '\0')
	{
		//resultat = position du caractere dans sa table * size de sa base/\(exponantiel sa pos dans la string)
		base_in_int += is_num_number_of(nbr[size_number - i - 1], base_from) * (to_power(size_base_from, i));
		i++;
	}
	return base_in_int;
}

int	main(void)
{
	//char *base1 = {"0123456789"};
	char *num = "f00";
	char *base2 = {"0123456789abcdef"};
	printf("%i\n", ft_convert_to_int(num, base2));
	return 0;
}
/*
je recoit une chaine de charactere et une "base", base possedant size chiffres
je veux convertir cette chaine en sa version int
	v1 je vais loop a travers la chaine en transfor;ant i en le faisant devenir chacun des chiffre de la base size fois
	v2 ou alors je passe dans chacun des caracteres de la chaine. 
	pour chaque caractere je le fais passer dans la table de ses chiffre et je regarde en quelle position il est.
	je cree un int result_int
	je fait resultat += (position du character dans sa table (en compttant 0 = 1) exposant (position du character en partant de 0) * size)
	exemple : pour FF (base 16) f = le chiffre numero 15 (en comptant le 0 numero 1) donc du coup ca fait 16 * 1 (pour le f pos 1) + 15 * 2 (celui pos 2) = 
	1101 = 1* (size exponantiel 0) + 0*10 + 1*(size * size) + 1 * (size * size *size)
	resultat = position du caractere dans sa table * size de sa base/\(exponantiel sa pos dans la string)
*/