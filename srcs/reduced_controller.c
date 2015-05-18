/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduced_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 16:39:19 by abellion          #+#    #+#             */
/*   Updated: 2015/03/25 17:49:26 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computor.h"

void		reduced_put(t_parts *parts)
{
	if (parts)
	{
		printf("\033[0;32mReduced form : \033[0m\t\t");
		if (parts->b_e)
			put_part(parts->b_e);
		else
			printf("0 ");
		printf("= 0\n");
	}
}

int			termequ(char *a, char *b)
{
	if (!a && !b)
		return (1);
	else if (!a || !b)
		return (0);
	a = (a[0] == '-') ? &a[1] : a;
	b = (b[0] == '-') ? &b[1] : b;
	return (ft_strequ(a, b));
}

t_terme		*find_same_terme(t_terme *lst, t_terme *elem)
{
	while (lst && elem)
	{
		if (lst != elem && termequ(lst->b, elem->b))
			return (lst);
		lst = lst->next;
	}
	return (0);
}

t_terme		*termes_to_opposite(t_terme *lst)
{
	t_terme		*begin;

	begin = lst;
	while (lst)
	{
		lst->a = -lst->a;
		lst = lst->next;
	}
	return (begin);
}

t_parts		*reduced_controller(t_parts *parts)
{
	t_terme		*elem;
	t_terme		*begin;

	if (!parts || !parts->b_e || !parts->a_e)
		return (0);
	begin = parts->b_e;
	while (parts->b_e->next)
		parts->b_e = parts->b_e->next;
	parts->a_e = termes_to_opposite(parts->a_e);
	parts->b_e->next = parts->a_e;
	parts->b_e = begin;
	while (parts->b_e)
	{
		if ((elem = find_same_terme(begin, parts->b_e)))
			operation_add(&elem, &parts->b_e);
		parts->b_e = parts->b_e->next;
	}
	parts->a_e = NULL;
	parts->b_e = begin;
	return (parts);
}
