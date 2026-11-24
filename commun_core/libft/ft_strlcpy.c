/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:49:34 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/17 22:28:55 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    //je dois calculer la longueur de src
    size_t src_size;
    size_t i;

    src_size = 0;
    i = 0;
    if (src == NULL)
        return (0);
    while(src[src_size])
    {
        src_size++;
    }
    if(size == 0)
        return (src_size);
    while(i < size - 1 && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return src_size;
}
