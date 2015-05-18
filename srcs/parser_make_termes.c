/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_make_termes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 16:39:09 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 20:43:33 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computor.h"

int				signe_produit(char *part)
{
	int			s_prod;
	int			s_fac1;
	int			s_fac2;
	char		**splits;

	splits = ft_strsplit(part, '*');
	s_fac1 = (splits[0] && splits[0][0] == '-') ? -1 : 1;
	s_fac2 = (splits[1] && splits[1][0] == '-') ? -1 : 1;
	if (s_fac1 + s_fac2 == -2 || s_fac1 + s_fac2 == 2)
		s_prod = 1;
	else
		s_prod = -1;
	ft_tabdel(&splits);
	return (s_prod);
}

t_terme			*parser_terme_two(t_terme *terme, char *part)
{
	char		*fac1;
	char		*fac2;
	int			s_fac1;
	int			s_prod;
	char		**splits;

	s_prod = signe_produit(part);
	splits = ft_strsplit(part, '*');
	if (splits && splits[0] && splits[1])
	{
		fac1 = (ft_strchr(splits[0], 'X')) ? splits[1] : splits[0];
		fac2 = (ft_strchr(splits[0], 'X')) ? splits[0] : splits[1];
		fac2 = (fac2[0] == '+' || fac2[0] == '-') ? &fac2[1] : fac2;
		s_fac1 = (fac1[0] == '-') ? -1 : 1;
		terme->a = (s_fac1 != s_prod) ? ft_atof(fac1) * -1 : ft_atof(fac1);
		terme->b = ft_strdup(fac2);
	}
	ft_tabdel(&splits);
	return (terme);
}

t_terme			*parser_terme_one(t_terme *terme, char *part)
{
	int			s_prod;

	if (!part)
		return (terme);
	s_prod = signe_produit(part);
	if (part[0] == '-' || part[0] == '+')
		part = &part[1];
	if (part[0] == 'X')
	{
		terme->a = (s_prod > 0) ? 1 : -1;
		terme->b = ft_strdup(part);
	}
	else
	{
		terme->a = (s_prod < 0) ? ft_atof(part) * -1 : ft_atof(part);
		terme->b = NULL;
	}
	return (terme);
}

t_terme			*parser_make_termes(char **parts)
{
	int			index;
	t_terme		*begin;
	t_terme		*termes;

	termes = terme_init();
	begin = termes;
	index = 0;
	while (parts && parts[index])
	{
		termes->next = terme_init();
		if (ft_strchr(parts[index], '*'))
			termes->next = parser_terme_two(termes->next, parts[index]);
		else
			termes->next = parser_terme_one(termes->next, parts[index]);
		termes = termes->next;
		index++;
	}
	return (begin->next);
}
