/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:53:46 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/11 16:58:56 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void ft_bzero(void *p, size_t size)
{
    unsigned char *bytes;
    size_t i;

    bytes = p;
    i = 0;
    while(i < size)
    {
        bytes[i] = 0;
        i++;
    }
}