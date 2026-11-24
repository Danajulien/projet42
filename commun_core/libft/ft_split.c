/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 14:13:44 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/24 17:04:30 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_word_count(char *s, char sep)
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
		if (s[i] && s[i] != sep)
		{
			count++;
			while (s[i] && s[i] != sep)
				i++;
		}
	}
	return (count);
}

int	ft_len_to_sep(char *s, char sep)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != sep)
	{
		i++;
	}
	return (i);
}

char *ft_strdup(char *s, size_t len)
{
	size_t i;
	char *new_str;

	i = 0;
	if (s == NULL)
		return (NULL);
	new_str = malloc(sizeof(char) * ft_len_to_sep(s, '\0') + 1);
	if (new_str == NULL)
		return (NULL);
	while (s[i])
	{
		i++;
	}
}

void	ft_free(char **words)
{
	size_t	i;
	size_t	j;

	if (words == NULL)
	{
		free(words);
		return ;
	}
	i = 0;
	j = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char *s, char sep)
{
	size_t	word_count;
	size_t	i;
	size_t	j;
	char	**word_array;

	if (s == NULL)
		return (NULL);
	word_count = ft_word_count(s, sep);
	word_array = malloc(sizeof(char *) * word_count + 1);
	if (word_count == 0 || word_array == NULL)
		return (NULL);// jsp si je dois quand meme malloc pour un NULL
	while
}