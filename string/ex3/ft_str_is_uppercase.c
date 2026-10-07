/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:07:44 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/07 15:16:32 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
	if (str[i] > 'Z' || str[i] < 'A')
		return (0);
	i++;
	}
	return (1);
}
#include <stdio.h>
int	main(void)
{
	printf("result : %d", ft_str_is_uppercase("AAAAAAAAAHb"));
	return (0);
}
