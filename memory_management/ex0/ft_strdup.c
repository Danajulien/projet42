/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 15:14:20 by marvin            #+#    #+#             */
/*   Updated: 2026/10/12 15:14:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(char *src)
{
	int	*copy;
	int	i;

    while (src[i] != '\0')
	{
        i++;
    }
    copy = malloc((i + 1)* sizeof(char));
    if (copy == NULL)
        return (NULL);
	i = 0;
    while(src[i] != '\0')
    {
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}