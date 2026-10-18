/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:53:28 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/12 19:30:18 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	i;
	int	*tab_min_max;

	if (min >= max)
		return (NULL);
	range = max - min;
	i = 0;
	tab_min_max = malloc((range) * sizeof(int));
	while (i < range)
	{
		tab_min_max[i] = min + i;
		i++;
	}
	return (tab_min_max);
}

int	main(void)
{
	int	*pt = ft_range(4, 10);
	printf("adresse pointee : %p\n", pt);
	//printf("liste : %i", *pt);
	for (int i = 0; i < 6; i++)
	{
		printf("%i", pt[i]);
	}
	free(pt);
	return (0);
}