/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 01:18:46 by marvin            #+#    #+#             */
/*   Updated: 2026/11/14 01:18:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char    *ft_strrchr(const char *s, int c)
{
    int i;
    int index;

    i = 0;
    index = -1;
    while(s[i])
    {
        if(s[i] == (char)c)
            index = i;
        i++;
    }
    if(s[i] == (char)c)
        index = i;
    if (index == -1)
        return (NULL);
    return ((char *)s + index);
}