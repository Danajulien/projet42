/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:36:56 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/12 19:30:44 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int	range_min_max;
	int i;
	
	if (min >= max)
    {
		range =  NULL;
		return (0);	
    }
	range_min_max = max - min;
	printf("range : %i", range_min_max);
	i = 0;
	*range = malloc(range_min_max * sizeof(int));
	if (*range == NULL)
		return -1;
	while(i < range_min_max)
	{
		printf("range : %i", range_min_max);
		range[0][i] = min + i;
		i++;
	}
	return (range_min_max);
}
int	main(void)
{
	int *pt;
	int **p_pt = &pt;
	int range = ft_ultimate_range(p_pt, 4, 10);
	printf("%p  est l'adresse ou est stocké : %p", p_pt, pt);
	
	printf("adresse pointee : %p\n", pt);
	printf("taille : %i\n", range);
	printf("liste : ");
	for(int i = 0; i < 6; i++)
	{
	printf("%i", pt[i]);
	}
	free(pt);
	return 0;
}