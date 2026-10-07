/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 13:09:46 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/07 14:51:39 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'A' || str[i] > 'z') || (str[i] > 'Z' && str[i] < 'A'))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <unistd.h>
int	main(void)
{
	char retour = '0';
	retour += ft_str_is_alpha("bonjourjaimelesharicots");
	write(1, &retour, 1);
	return (0);
}
*/
