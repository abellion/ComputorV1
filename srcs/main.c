/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 17:42:43 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 20:44:27 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computor.h"

void		put_part(t_terme *termes)
{
	int			i;
	double		nbr;
	char		*str;

	i = 0;
	while (termes)
	{
		nbr = termes->a;
		str = termes->b;
		if (i && nbr > 0)
			printf("+ ");
		if (nbr == 1 && str)
			printf("%s ", str);
		else if (nbr == -1 && str)
			printf("-%s ", str);
		else if (str)
			printf("%3.2f * %s ", nbr, str);
		else
			printf("%3.2f ", nbr);
		i++;
		termes = termes->next;
	}
}

int			solver_launcher(t_terme *lst, int poly_nb)
{
	printf("\n\033[0;32mThe solution is :\033[0m");
	if (poly_nb == 2)
		solver_deg2(lst);
	else if (poly_nb == 1)
		solver_deg1(lst);
	else if (poly_nb == 0)
		solver_deg0(lst);
	else
		printf("\t\033[1;32mAll real are solution.\n\033[0m");
	return (0);
}

int			main(int ac, char **av)
{
	t_parts		*parts;
	float		polynomial_nb;

	if (ac != 2)
		return (ft_putendl("\033[0;31mInput Error.\033[0m"), 0);
	parts = parser_controller(ft_strdup(av[1]));
	if (parts && parts->b_e && parts->a_e)
	{
		parts = reduced_controller(parts);
		parts->b_e = parser_sort_termes(parts->b_e);
		parts->b_e = termes_clear(parts->b_e);
		reduced_put(parts);
		polynomial_nb = polynomial_controller(parts->b_e);
		polynomial_put(polynomial_nb);
		if ((polynomial_nb >= 0 && polynomial_nb <= 2) || !parts->b_e)
			solver_launcher(parts->b_e, polynomial_nb);
		else
			printf("\n\033[0;31mCan't solve it.\033[0m\n");
	}
	else
		ft_putendl("\033[0;31mInput Error.\033[0m");
	parts_del(&parts);
	ac = 0;
	return (0);
}
