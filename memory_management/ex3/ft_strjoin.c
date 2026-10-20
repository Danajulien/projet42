/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:15:36 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/20 17:44:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_cpy(int size, char *str_united, char **strs, char *sep)
{
	int	i[3];

	i[0] = -1;
	i[1] = 0;
	i[2] = 0;
	while (++i[0] < size)
	{
		while (strs[i[0]][i[1]] != '\0')
		{
			str_united[i[2]] = strs[i[0]][i[1]];
			i[1]++;
			i[2]++;
		}
		i[1] = 0;
		if (i[0] != (size - 1))
		{
			while (sep[i[1]] != '\0')
			{
				str_united[i[2]] = sep[i[1]];
				i[1]++;
				i[2]++;
			}
		}
		i[1] = 0;
	}
}

int	count_char(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

void	char_count(int *i, int size, char **strs, int *char_in_strs)
{
	while (i[0] < size)
	{
		while (strs[i[0]][i[1]] != '\0')
		{
			i[1]++;
			(*char_in_strs)++;
		}
		i[0]++;
		i[1] = 0;
	}
	i[0] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		char_in_strs;
	int		i[3];
	char	*str_united;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (size == 0)
	{
		str_united = malloc(sizeof(char));
		if (str_united == NULL)
			return (NULL);
		str_united[0] = '\0';
		return (str_united);
	}
	char_in_strs = 0;
	char_count(i, size, strs, &char_in_strs);
	char_in_strs += (count_char(sep) * (size - 1));
	str_united = malloc((char_in_strs + 1) * sizeof(char));
	if (str_united == NULL)
		return (NULL);
	ft_cpy(size, str_united, strs, sep);
	str_united[char_in_strs] = '\0';
	return (str_united);
}
// int	main(void)
// {
// 	char	*dico[] = {"y'a", "un", "serpent", "dans", "ma", "botte"};
// 	char	*str;
// 	str = ft_strjoin(6, dico, "------");
// 	printf("%s", str);
// 	return (0);
// }