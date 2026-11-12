/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:25:47 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/12 17:16:11 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memmove(void *dst, void *src, size_t n)
{
    unsigned char* bytes_src;
    unsigned char* bytes_dst;
    size_t i;
    int reverse_copy;

    bytes_src = src;
    bytes_dst = dst;
    i = 0;
    reverse_copy = 0;
    if(n == 0)
        return dst;
    if(n == 0)
        return dst;
    while (i < n)
    {
        //je check si a un moment dst + i = src
        if (bytes_src = bytes_dst - i)
            reverse_copy = 1;
        i++;
    }
    i = 0;
    while (i < n)
    {
        if (reverse_copy = 1)
            bytes_dst[n - i - 1] = bytes_src[n - i - 1];
        else
            bytes_dst[i] = bytes_src[i];
        i++;
    }
    return dst;
}
