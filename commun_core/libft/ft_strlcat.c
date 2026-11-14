/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:07:54 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/12 17:12:24 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t ft_strlcat(char *dst, char *src, size_t size)
{
    //tester si on trouve \0 dans les size premier octet de dst
    size_t i;
    size_t j;
    size_t dst_size;

    i = 0;
    j = 0;

    while(i < size && dst[i])
    {
        i++;
    }
    
    if (i == size)//on a pas trouve le \0 dans les size premiers octects
    {
        return (size + ft_strlen(src));
    }
    else
   {
        dst_size = i;
        while(i < size - 1 && src[j])
        {
            dst[i] = src[j];
            i++;
            j++;
        }
        dst[i] = '\0';
        return (dst_size + ft_strlen(src));
   }
}