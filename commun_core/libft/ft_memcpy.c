/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:11:07 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/11 17:19:22 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memcpy(void *src, void *dst, size_t n)
{
    unsigned char* bytes_src;
    unsigned char* bytes_dst;
    size_t i;

    bytes_src = src;
    bytes_dst = dst;
    i = 0;
    if (src == NULL || dst == NULL)//pas sur de si c est demande
        return NULL;
    while (i < n)
    {
        bytes_dst[i] = bytes_src[i];
        i++;
    }
    return dst;
}