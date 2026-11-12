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

size_t ft_strlcat(char *dst, char *src, size_t size)
{
    //tester si on trouve \0 dans les size premier octet de dst
    int i;

    i = 0;
    while(i < size && dst[i])
    {
        i++;
    }
    if (i == size)//on a pas trouve le \0 dans les size premiers octects
}