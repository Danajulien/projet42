/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:13:44 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/24 18:09:12 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_word_count(const char *s, const char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (s[i] != sep && s[i])
		{
			count++;
			while (s[i] != sep && s[i])
				i++;
		}
	}
	return (count);
}

int	ft_len_to_sep(const char *s, const char sep)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != sep && s[i])
	{
		i++;
	}
	return (i);
}

void	ft_free(char **words)
{
	size_t	i;

	i = 0;
	if (words == NULL)
	{
		free(words);
		return ;
	}
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(const char *s, const char sep)
{
	size_t	word_count;
	size_t	i;
	size_t	j;
	char	**word_array;

	if (s == NULL)
		return (NULL);
	word_count = ft_word_count(s, sep);
	word_array = malloc(sizeof(char *) * word_count + 1);
	i = 0;
	j = 0;
	if (word_count == 0 || word_array == NULL)
	{
		free(word_array);
		return (NULL);// jsp si je dois quand meme malloc pour un NULL
	}
	while (i < word_count)
	{
		while (s[j] == sep)
			j++;
		word_array[i] = ft_substr(s, (unsigned int)j, ft_len_to_sep(s, sep) + 1);
		while (s[j] != sep && s[j])
			j++;
		i++;
	}
	word_array[i] = NULL;
	return(word_array);
}