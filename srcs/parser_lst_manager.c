/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lst_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:10:32 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 20:31:42 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computor.h"

t_terme			*terme_init(void)
{
	t_terme		*terme;

	if (!(terme = (t_terme *)malloc(sizeof(t_terme))))
		return (0);
	terme->b = NULL;
	terme->next = NULL;
	return (terme);
}

t_parts			*parts_init(void)
{
	t_parts		*parts;

	if (!(parts = (t_parts *)malloc(sizeof(t_parts))))
		return (0);
	parts->b_e = NULL;
	parts->a_e = NULL;
	return (parts);
}

void			terme_delone(t_terme **terme)
{
	if (terme && *terme)
	{
		ft_strdel(&(*terme)->b);
		free(*terme);
		*terme = NULL;
	}
}

void			terme_delall(t_terme **terme)
{
	t_terme		*next;

	while (terme && *terme)
	{
		next = (*terme)->next;
		terme_delone(terme);
		*terme = next;
	}
}

void			parts_del(t_parts **parts)
{
	if (parts && *parts)
	{
		terme_delall(&(*parts)->b_e);
		free(*parts);
		*parts = NULL;
	}
}
