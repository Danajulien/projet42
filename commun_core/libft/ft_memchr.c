/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 01:53:34 by marvin            #+#    #+#             */
/*   Updated: 2026/11/14 01:53:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *ptr;
    size_t i;

    ptr = s;
    i = 0;
    while(i < n)
    {
        if(ptr[i] == (unsigned char)c)
            return (ptr + i);
        i++;
    }
    return NULL;
}