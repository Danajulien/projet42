/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:15:36 by jlodenot          #+#    #+#             */
/*   Updated: 2026/10/12 19:31:10 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep)
{
    int char_in_strs;
    int i;
    int j;
    int k;
    char    *str_united;
    if (size == 0)
    {
        free(str_united);
        return (str_united);
    }
    char_in_strs = 0;
    i = 0;
    j = 0;
    k = 0;
    while(i < size)
    {
        while(strs[i][j] != '\0')
        {
            j++;
            char_in_strs++;
        }
        i++;
        j = 0;
    }
    i = 0;
    while (sep[i] != '\0')
    {
        i++;
    }
    char_in_strs += i;
    str_united = malloc((char_in_strs + 1) * sizeof(char));
    i = 0;
    j = 0;
    while(i < size)
    {
        while(strs[i][j] != '\0')
        {
            str_united[k] = strs[i][j];
            j++;
            k++;
        }
        j = 0;
        if (i != (size - 1))
        {
            while(sep[j] != '\0')
            {
                str_united[k] = sep[j];
                j++;
                k++;
            }
        }
        
        j = 0;
        i++;
    }
    str_united[k] = '\0';
    return (str_united);
}

int main(void)
{
    char *dico[] = {"haricot", "vert", "beurre"};
    char *str = ft_strjoin(3, dico, "--");
    printf("%s", str);
    return 0;
}
