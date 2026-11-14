/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 02:08:17 by marvin            #+#    #+#             */
/*   Updated: 2026/11/14 02:08:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;
    const char  *str;
    if(ft_strlen(little) == 0)
        return ((char *)big);
    i = 0;
    j = 0;
    while(i < len && big[i])
    {
        if(big[i] == little[j])
        {
            str = big + i;
            while (i < len && big[i] == little[j] && little[j])
            {
                j++;
                i++;
            }
            if (little[j] == '\0')
                return ((char *)str);
            if (i == len)
                return NULL;
            i -= j;
            j = 0;
        }
        i++;
    }
    return NULL;
}