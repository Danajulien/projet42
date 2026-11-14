/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 01:11:32 by marvin            #+#    #+#             */
/*   Updated: 2026/11/14 01:11:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char    *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == (char)c)
            return ((char *)s + i);
        i++;
    }
    if(s[i] == (char)c)
        return ((char *)s + i);
    return NULL;
}