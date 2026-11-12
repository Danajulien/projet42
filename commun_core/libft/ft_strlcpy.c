/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:49:34 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/12 17:16:52 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t ft_strlcpy(char *dst, char *src, size_t size)
{
    //je dois calculer la longueur de src
    int src_size;
    int i;

    src_size = 0;
    i = 0;
    if(size == 0)
        return (0);
    while(src[src_size])
    {
        src_size++;
    }
    while(i < size - 1 && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return src_size;
}