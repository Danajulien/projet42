/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 18:10:25 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/25 17:25:10 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

size_t	num_size(int n)
{
	size_t	i;

	i = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	to_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	size_t	size;
	size_t	i;
	int		is_neg;
	char	*num_char;

	size = num_size(n);
	is_neg = (n < 0);
	i = 0;
	num_char = malloc(sizeof(char) * (size + 1 + is_neg));
	while (i < size)
	{
		num_char[size - 1 + is_neg - i] = '0' + to_abs(n % 10);
		n /= 10;
		i++;
	}
	if (is_neg)
		num_char[0] = '-';
	num_char[i + is_neg] = '\0';
	return (num_char);
}
