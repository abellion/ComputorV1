/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termes_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 16:39:26 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 20:30:43 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computor.h"

t_terme		*terme_pop(t_terme *lst, t_terme *elem)
{
	t_terme		*tmp;
	t_terme		*prev;
	t_terme		*begin;

	prev = NULL;
	begin = lst;
	while (lst && lst != elem)
	{
		prev = lst;
		lst = lst->next;
	}
	if (prev)
		prev->next = lst->next;
	else
		tmp = (begin) ? begin->next : NULL;
	terme_delone(&elem);
	return ((prev) ? begin : tmp);
}

t_terme		*terme_swap(t_terme *lst, t_terme *elem)
{
	t_terme		*prev;
	t_terme		*suiv;
	t_terme		*begin;

	if (!lst || !lst->next || !elem)
		return (lst);
	prev = NULL;
	begin = lst;
	suiv = elem->next;
	while (lst->next != elem && (prev = lst))
		lst = lst->next;
	if (prev)
	{
		prev->next = elem;
		elem->next = lst;
		lst->next = suiv;
	}
	else
	{
		begin = elem;
		begin->next = lst;
		lst->next = suiv;
	}
	return (begin);
}

int			termes_count(t_terme *lst)
{
	int			nb;

	nb = 0;
	while (lst)
	{
		nb++;
		lst = lst->next;
	}
	return (nb);
}

t_terme		*termes_clear(t_terme *lst)
{
	t_terme		*next;
	t_terme		*begin;

	begin = lst;
	while (lst)
	{
		next = lst->next;
		if (lst->a == 0 || lst->a == -0)
			begin = terme_pop(begin, lst);
		lst = next;
	}
	return (begin);
}
