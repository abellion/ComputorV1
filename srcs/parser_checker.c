/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 20:30:15 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 20:30:16 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computor.h"

int				check_unknown(char p)
{
	if (!p || (p == '*' || p == '+' || p == '-'))
		return (1);
	return (0);
}

int				check_exponent(char p, char s)
{
	if (p && s && p == 'X' && ft_isdigit(s))
		return (1);
	return (0);
}

int				check_other(char c, char p, char s)
{
	if (ft_isdigit(c) || c == 'X' || c == '^')
		return (1);
	else if ((c == '+' || c == '-') && (ft_isdigit(s) || s == 'X'))
		return (1);
	else if (c == '.' && ft_isdigit(p) && ft_isdigit(s))
		return (1);
	else if (c == '*' && p && s)
	{
		if ((ft_isdigit(p) && s == 'X') || (ft_isdigit(s) && p == 'X'))
			return (1);
	}
	return (0);
}

int				check_nbr(char *part)
{
	int		i_tab;
	int		i_str;
	int		count;
	char	**splits;

	i_tab = 0;
	splits = ft_strsplit(part, '*');
	while (splits && splits[i_tab])
	{
		i_str = 0;
		count = 0;
		while (splits[i_tab][i_str++])
			count = (splits[i_tab][i_str] == '.') ? count + 1 : count;
		if (count > 1)
			return (0);
		i_tab++;
	}
	return (1);
}

int				parser_checker(char **tab, char *available)
{
	char	c;
	char	p;
	char	*str;

	p = 0;
	str = (tab) ? tab[0] : NULL;
	if (!check_nbr(str))
		return (0);
	while (str && *str)
	{
		c = *str;
		if (!ft_isdigit(c) && !ft_strchr(available, c))
			return (0);
		else if (c == 'X' && !check_unknown(p))
			return (0);
		else if (c == '^' && !check_exponent(p, *(str + 1)))
			return (0);
		else if (!check_other(c, p, *(str + 1)))
			return (0);
		p = c;
		str++;
	}
	return ((tab && tab[1]) ? parser_checker(&tab[1], available) : 1);
}
