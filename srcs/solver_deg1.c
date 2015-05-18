/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_deg1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 16:38:34 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 19:41:54 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computor.h"

int		solver_deg1(t_terme *lst)
{
	double		a;
	double		b;
	int			nb_termes;

	nb_termes = termes_count(lst);
	a = lst->a;
	b = (nb_termes > 1) ? lst->next->a : 0;
	printf("\tLinear of form a * X + b = 0\n");
	printf("\t\t\tHere, a = %3.2f and b = %3.2f\n", a, b);
	printf("\t\t\tSo, we've got \t%3.2f * X + %3.2f = 0\n", a, b);
	printf("\t\t\t\t\t%3.2f * X = %3.2f\n", a, -b);
	printf("\t\t\t\t\tX = %3.2f / %3.2f\n", -b, a);
	printf("\t\t\t\t\t\033[1;32mX = %3.2f\033[0m\n", -b / a);
	return (0);
}
