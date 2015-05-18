/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sort_termes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 20:30:29 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 20:34:27 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computor.h"

float		parser_sort_get(char *str)
{
	char		*exponent_str;
	double		exponent_nbr;

	exponent_nbr = -2147483648;
	if ((exponent_str = ft_strchr(str, '^')))
		exponent_nbr = ft_atof(&exponent_str[1]);
	else if ((exponent_str = ft_strchr(str, 'X')))
		exponent_nbr = 1;
	return (exponent_nbr);
}

t_terme		*parser_sort_termes(t_terme *lst)
{
	t_terme		*next;
	t_terme		*prev;
	t_terme		*begin;
	int			change;

	change = 1;
	begin = lst;
	while (change)
	{
		change = 0;
		prev = NULL;
		lst = begin;
		while (lst)
		{
			next = lst->next;
			if (prev && parser_sort_get(lst->b) > parser_sort_get(prev->b))
			{
				begin = terme_swap(begin, lst);
				change = 1;
			}
			prev = lst;
			lst = next;
		}
	}
	return (begin);
}
