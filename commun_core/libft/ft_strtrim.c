/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 22:37:36 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/20 00:41:17 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int is_set(const char c, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	last;
	size_t	alloc_len;
	char	*s2;
	int have_to_set;
	/*
    Je dois reussir a recuperer la taille de la partie du milieu
	pour ca je dois recuperer l index du premier char apres un ensemble de set, jusqu a lensemble de set final
	pour ca je dois parcourir la string tant que je trouve des char de set a la suite
    des que je trouve un char qui n est pas un set, je stock le start
    */
	if (s1 == NULL || set == NULL)
		return NULL;
	i = 0;
	have_to_set = 1;
	while (is_set(s1[i], set))
	{
		i++;
	}
	start = i;
	last = i;
	while (s1[i++])
	{
		//"abcdba", "abc"
		while (!is_set(s1[i], set) && s1[i])
		{
			i++;
			have_to_set = 1;
		}
		if (have_to_set)
			last = i;
		have_to_set = 0;
	}
	alloc_len = last - start;
	s2 = ft_substr(s1, start, alloc_len);
	if (s2 == NULL)
		return (NULL);
	return (s2);
}

