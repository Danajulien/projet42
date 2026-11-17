/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 20:55:11 by marvin            #+#    #+#             */
/*   Updated: 2026/11/15 20:55:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int is_num (char c)
{
    if(c >= '0' && c <= '9')
        return (1);
    return (0);
}

int ft_atoi(const char *s)
{
    int is_neg;
    int num;
    int i;

    num = 0;
    i = 0;
    is_neg = 0;
    
    while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
        i++;
    if(s[i] == '-')
    {
        is_neg = 1;
        i++;
    }
    else if(s[i] == '+')
    {
        i++;
    }
    while(s[i] && is_num(s[i]))
    {
        if (is_neg)
            num = (num * 10) - (s[i] - '0');
        else
            num = (num * 10) + (s[i] - '0');
        i++;
    }
    return num;
}