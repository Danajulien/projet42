/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 16:04:41 by marvin            #+#    #+#             */
/*   Updated: 2026/11/15 16:04:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int     ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *ptr1;
    const unsigned char *ptr2;
    size_t i;

    ptr1 = s1;
    ptr2 = s2;
    i = 0;
    while(i < n)
    {
        if (ptr1[i] != ptr2[i])
            return ((ptr1[i] - ptr2[i]));
        i++;
    }
    return (0);
}