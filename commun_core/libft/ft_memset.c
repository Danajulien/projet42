/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:31:03 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/11 17:09:05 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memset(void *p, int value, size_t count)
{
    unsigned char *bytes;
    size_t i;

    bytes = p;
    i = 0;
    while(i < count)
    {
        bytes[i] = (unsigned char)value;
        i++;
    }
    return p;
}