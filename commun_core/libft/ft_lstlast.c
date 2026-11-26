/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlodenot <jlodenot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 23:20:46 by jlodenot          #+#    #+#             */
/*   Updated: 2026/11/26 23:25:50 by jlodenot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*p;
	t_list	*last;

	p = lst;
	if (p == NULL)
		return (NULL);
	last = lst;
	while (p->next != NULL)
	{
		p = p->next;
		last = p;
	}
	return (last);
}