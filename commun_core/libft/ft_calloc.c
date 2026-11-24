/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 01:16:26 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/18 02:08:11 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void *ft_calloc(size_t n, size_t size)
{
    void *ptr;
    
    if (size != 0 && n > (size_t)-1 / size)
        return NULL;
    ptr = malloc(n * size);
    if (ptr == NULL)
        return (NULL);
    ft_memset(ptr, 0, n * size);
    return ptr;
}