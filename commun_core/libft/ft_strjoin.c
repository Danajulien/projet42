/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 20:29:03 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/19 20:50:12 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char *ft_strjoin(const char *s1, const char *s2)
{
	char *s3;
	size_t len1;
	size_t len2;
	size_t len3;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = len1 + len2;
	if(len3 == 0)
		return (ft_strdup(""));
	else if (len1 == 0)
		return (ft_strdup(s2));
	else if (len2 == 0)
		return (ft_strdup(s1));
	s3 = malloc(len3 * sizeof(char) + 1);
	if (s3 == NULL)
		return NULL;
	while(s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
