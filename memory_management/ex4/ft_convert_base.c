/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:33:29 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/19 13:53:32 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_valid_base(char *base);

int	is_num_number_of(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != c)
	{
		i++;
	}
	return (i);
}

int	to_power(int num, int power)
{
	int	i;

	i = num;
	if (power == 0)
		return (1);
	i *= to_power(i, power - 1);
	return (i);
}

char	*int_to_base(int num_int, char *base_to, int is_neg)
{
	int		i;
	int		nbr_len;
	int		copy_int;
	char	*new_nbr;

	nbr_len = 0;
	copy_int = num_int;
	while (copy_int > 0)
	{
		nbr_len++;
		copy_int /= is_num_number_of('\0', base_to);
	}
	copy_int = num_int;
	i = nbr_len - 1 + is_neg;
	new_nbr = malloc((nbr_len + 1 + is_neg) * sizeof(char));
	while (i >= is_neg && new_nbr != NULL)
	{
		new_nbr[i] = base_to[copy_int % is_num_number_of('\0', base_to)];
		copy_int /= is_num_number_of('\0', base_to);
		i--;
	}
	if (is_neg == 1)
		new_nbr[0] = '-';
	new_nbr[nbr_len + is_neg] = '\0';
	return (new_nbr);
}

int	ft_convert_to_int(char *nbr, char *base_from)
{
	int	size_base_from;
	int	i;
	int	base_in_int;
	int	size_num;
	int	is_neg;

	size_base_from = is_num_number_of('\0', base_from);
	is_neg = 0;
	if (nbr[0] == '-')
	{
		is_neg = 1;
	}
	size_num = (is_num_number_of('\0', nbr) - is_neg);
	i = 0;
	base_in_int = 0;
	while (nbr[i + is_neg] != '\0')
	{
		base_in_int += is_num_number_of(nbr[i + is_neg], base_from)
			* (to_power(size_base_from, size_num - 1 - i));
		i++;
	}
	if (nbr[0] == '-')
		return (-base_in_int);
	return (base_in_int);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	is_neg;
	int	nbr_int;

	if ((is_valid_base(base_from) == 0 || is_valid_base(base_to)) == 0)
		return (NULL);
	nbr_int = ft_convert_to_int(nbr, base_from);
	if (nbr_int < 0)
	{
		is_neg = 1;
		return (int_to_base(-nbr_int, base_to, is_neg));
	}
	else
	{
		is_neg = 0;
		return (int_to_base(nbr_int, base_to, is_neg));
	}
}

// int	main(void)
// {
// 	char	*base_10;
// 	char	*num;
// 	char	*base_hexa;
// 	char	*nbr_converted;

// 	// char *base_binaire = {"01"};
// 	base_10 = "0123456789";
// 	num = "-fe";
// 	base_hexa = "0123456789abcdef";
// 	nbr_converted = ft_convert_base(num, base_hexa, base_10);
// 	if (nbr_converted == NULL)
// 		return (1);
// 	printf("%i\n", ft_convert_to_int(num, base_hexa));
// 	printf("%s", nbr_converted);
// 	// printf("%s", int_to_base(255, base2));
// 	free(nbr_converted);
// 	return (0);
// }
