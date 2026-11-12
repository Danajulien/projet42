/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:11:07 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/12 17:15:02 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memcpy(void *dst, void *src, size_t n)
{
    unsigned char* bytes_src;
    unsigned char* bytes_dst;
    size_t i;

    bytes_src = src;
    bytes_dst = dst;
    i = 0;
    if(n == 0)
        return dst;
    
    while (i < n)
    {
        bytes_dst[i] = bytes_src[i];
        i++;
    }
    return dst;
}
