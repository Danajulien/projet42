/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:07:17 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/19 14:24:05 by jlodenot         ###   ########.fr       */
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

char	*ft_strcpy(char *str, char *str_src, int *str_i, char *sep)
{
	int	word_ar_i;

	word_ar_i = 0;
	str = malloc(sizeof(char)
			* (letter_in_word(str_src + *str_i, sep) + 1));
	while (is_sep(str_src[*str_i], sep) == 0)
	{
		str[word_ar_i] = str_src[*str_i];
		(*str_i)++;
		word_ar_i++;
	}
	str[word_ar_i] = '\0';
	return (str);
}

char	**ft_split(char *str, char *sep)
{
	int		str_i;
	int		word_total;
	char	**w_list;
	int		word_nbr;

	word_total = count_words(str, sep);
	w_list = malloc(sizeof(char *) * (word_total + 1));
	w_list[count_words(str, sep)] = NULL;
	word_nbr = 0;
	str_i = 0;
	while (word_nbr < word_total)
	{
		if ((str_i == 0 && is_sep(str[str_i], sep) == 1)
			|| (is_sep(str[str_i], sep)
				&& (is_sep(str[str_i - 1], sep))))
			str_i++;
		else
		{
			w_list[word_nbr] = ft_strcpy(w_list[word_nbr], str, &str_i, sep);
			word_nbr ++;
			str_i++;
		}
	}
	return (w_list);
}

// int	main(void)
// {
// 	char	*phrase = "kiwi du jardin de mami";
// 	char	**tab_words;
// 	char *sep = " \n";
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