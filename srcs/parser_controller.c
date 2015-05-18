/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:10:18 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 19:21:36 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computor.h"

int				count_equal(char *input)
{
	int		i;

	i = 0;
	while ((input = ft_strchr(input, '=')))
	{
		input = &input[1];
		i++;
	}
	return (i);
}

t_parts			*parser_controller(char *input)
{
	char		**b_e;
	char		**a_e;
	t_parts		*parts;
	char		**separe;
	char		*available;

	separe = ft_strsplit(input, '=');
	if (!input || !separe || ft_tablen(separe) != 2 || count_equal(input) > 1)
		return (0);
	parts = NULL;
	available = ft_strdup("X^*+-.");
	b_e = parser_make_parts(separe[0]);
	a_e = parser_make_parts(separe[1]);
	if (parser_checker(b_e, available) && parser_checker(a_e, available))
	{
		parts = parts_init();
		parts->b_e = parser_make_termes(b_e);
		parts->a_e = parser_make_termes(a_e);
	}
	ft_strdel(&available);
	ft_strdel(&input);
	ft_tabdel(&b_e);
	ft_tabdel(&a_e);
	return (parts);
}
