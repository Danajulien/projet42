/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 01:05:00 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/18 01:57:36 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char *ft_strdup(const char *s)
{
    size_t size;
    size_t i;
    char *dup;

    if (s == NULL)
        return NULL;
    size = ft_strlen(s);
    i = 0;
    dup = malloc(sizeof(char) * (size + 1));
    if (dup == NULL)
        return (NULL);
    while(s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}