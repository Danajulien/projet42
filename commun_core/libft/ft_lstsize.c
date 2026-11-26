/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 23:07:30 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/26 23:09:30 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int ft_lstsize(t_list *lst)
{
	t_list *p;
	unsigned int count;

	p = lst;
	count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return (count);
}