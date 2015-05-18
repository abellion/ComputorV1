/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_make_parts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 16:39:04 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 18:51:09 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computor.h"

int			parser_is_part(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

char		*parser_next_part(char *input)
{
	int		mult;
	char	prev;
	int		index;

	mult = 0;
	prev = 0;
	index = 0;
	while (input && input[index])
	{
		mult = (input[index] == '*') ? mult + 1 : mult;
		if ((prev && prev != '*' && parser_is_part(input[index])) || mult > 1)
			return (&input[index]);
		prev = input[index];
		index++;
	}
	return ((input) ? &input[index] : 0);
}

int			parser_count_parts(char *input)
{
	int		nb;

	nb = 0;
	while (input && input[0])
	{
		input = parser_next_part(input);
		nb++;
	}
	return (nb);
}

char		**parser_make_parts(char *input)
{
	char	**parts;
	char	*tmp;
	int		index;
	int		nb_parts;

	index = 0;
	input = ft_tabtostr(ft_strsplit(input, ' '));
	nb_parts = parser_count_parts(input);
	if (!input || !(parts = (char **)malloc(sizeof(char *) * (nb_parts + 1))))
		return (0);
	while (input && input[0])
	{
		tmp = parser_next_part(input);
		parts[index] = ft_strsub(input, 0, ft_strlen(input) - ft_strlen(tmp));
		input = tmp;
		index++;
	}
	parts[index] = NULL;
	return (parts);
}
