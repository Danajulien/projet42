/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:07:17 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/21 01:25:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i] || c == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	letter_in_word(char *str, char *sep)
{
	int	i;

	i = 0;
	while (is_sep(str[i], sep) == 0 && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	count_words(char *str, char *sep)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		if ((is_sep(str[i + 1], sep) == 1 && is_sep(str[i], sep) != 1)
			|| (str[i + 1] == '\0' && is_sep(str[i], sep) == 0))
			word_count++;
		i++;
	}
	return (word_count);
}

char	*ft_strcpy(char *str_src, int *i, char *sep)
{
	char	*str;
	int		word_ar_i;

	word_ar_i = 0;
	str = malloc(sizeof(char)
			* (letter_in_word(str_src + *i, sep) + 1));
	if (str == NULL)
		return (NULL);
	while (is_sep(str_src[*i], sep) == 0 && str_src[*i] != '\0')
	{
		str[word_ar_i] = str_src[*i];
		(*i)++;
		word_ar_i++;
	}
	str[word_ar_i] = '\0';
	return (str);
}

char	**ft_split(char *str, char *sep)
{
	int		i;
	char	**w_list;
	int		word_nbr;
	int		word_total;

	word_total = count_words(str, sep);
	w_list = malloc(sizeof(char *) * word_total + 1);
	if (w_list == NULL)
		return (NULL);
	w_list[word_total] = NULL;
	word_nbr = 0;
	i = 0;
	while (word_nbr < word_total)
	{
		if (is_sep(str[i], sep) == 0)
		{
			w_list[word_nbr] = ft_strcpy(str, &i, sep);
			if (w_list[word_nbr] == NULL)
				return (NULL);
			word_nbr++;
		}
		i++;
	}
	return (w_list);
}
// int	main(void)
// {
// 	char	*phrase = "les raisins du jardin de mamie";
// 	char	**tab_words;
// 	char *sep = " \n\t";
// 	tab_words = ft_split(phrase, sep);
// 	int i = 0;
// 	while (tab_words[i] != NULL)
// 	{
// 		printf("%s\n", tab_words[i]);
// 		free(tab_words[i]);
// 		i++;
// 	}
// 	free(tab_words);
// 	return 0;
// }