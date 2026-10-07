/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 14:52:30 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/07 14:58:49 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] >= '9')
			return (0);
		i++;
	}
	return (1);
}
#include <stdio.h>
int	main(void)
{
	printf("return = %d", ft_str_is_numeric("02de02"));
	return (0);
}
