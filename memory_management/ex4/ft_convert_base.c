/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:33:29 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/21 01:27:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

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

char	*int_to_base(long num_int, char *base_to, int is_neg)
{
	int			i;
	int			nbr_len;
	long		copy_int;
	char		*new_nbr;

	nbr_len = 1;
	copy_int = num_int / is_num_number_of('\0', base_to);
	while (copy_int > 0)
	{
		nbr_len++;
		copy_int /= is_num_number_of('\0', base_to);
	}
	i = nbr_len - 1 + is_neg;
	new_nbr = malloc((nbr_len + 1 + is_neg) * sizeof(char));
	while (i >= is_neg && new_nbr != NULL)
	{
		new_nbr[i] = base_to[num_int % is_num_number_of('\0', base_to)];
		num_int /= is_num_number_of('\0', base_to);
		i--;
	}
	if (is_neg == 1 && new_nbr != NULL)
		new_nbr[0] = '-';
	if (new_nbr != NULL)
		new_nbr[nbr_len + is_neg] = '\0';
	return (new_nbr);
}

long	ft_convert_to_int(char *nbr, char *base_from)
{
	int		size_base_from;
	int		i;
	long	base_in_int;
	int		is_neg;

	size_base_from = is_num_number_of('\0', base_from);
	is_neg = 0;
	if (nbr[0] == '-')
	{
		is_neg = 1;
	}
	i = 0;
	base_in_int = 0;
	while (nbr[i + is_neg] != '\0')
	{
		base_in_int = (base_in_int * size_base_from)
			+ is_num_number_of(nbr[i + is_neg], base_from);
		i++;
	}
	if (nbr[0] == '-')
		return (-base_in_int);
	return (base_in_int);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		is_neg;
	long	nbr_int;

	if ((is_valid_base(base_from) == 0 || is_valid_base(base_to) == 0))
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
// 	num = "000511";
// 	base_hexa = "0123456789abcdef";
// 	nbr_converted = ft_convert_base(num, base_10, base_hexa);
// 	if (nbr_converted == NULL)
// 		return (1);
// 	//printf("%i\n", ft_convert_to_int(num, base_hexa));
// 	printf("%s", nbr_converted);
// 	// printf("%s", int_to_base(255, base2));
// 	free(nbr_converted);
// 	return (0);
// }
