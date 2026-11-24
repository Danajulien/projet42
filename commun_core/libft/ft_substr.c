/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:16:26 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/19 20:16:26 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char *ft_substr(char const *s,
                unsigned int start,
                size_t len)
{
    //il faut que je calcule la longueur a allouer, depuis le start jusqu a la fin de s ou len selon ce qui est plus court
    size_t alloc_len;
    size_t i;
    char *dst;

    i = 0;
    if(start > ft_strlen(s))
        return(ft_strdup(""));
    alloc_len = ft_strlen(s + start);
    if (alloc_len > len)
        alloc_len = len;
    dst = malloc(alloc_len * sizeof(char) + 1);
    if (dst == NULL)
        return NULL;
    while(s[i + start] && i < len)
    {
        dst[i] = s[i + start];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}