/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 00:43:08 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/26 01:14:50 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	size_t	len;
	char	*s;

	s = ft_itoa(n);
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		write(fd, s + i, 1);
		i++;
	}
	free(s);
}
