/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_deg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 16:22:04 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 20:46:14 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computor.h"

void		solver_deg2_izero(double a, double b, double delta)
{
	double		nb1;
	double		nb2;
	double		nb3;

	nb1 = -b;
	nb2 = ft_sqrt(delta * -1);
	nb3 = 2 * a;
	printf("\t\t\tDelta is < 0.\n");
	printf("\t\t\tThis equation has two solutions in C :\n");
	printf("\t\t\t\t--> z1 = (-b -i * sqrt(-delta)) / (2 * a)\n");
	printf("\t\t\t\t--> z2 = (-b +i * sqrt(-delta)) / (2 * a)\n");
	printf("\033[1;32m");
	printf("\t\t\tz1 = %3.2f / %3.2f + i * %f\n", nb1, nb3, nb2 / nb3);
	printf("\t\t\tz2 = %3.2f / %3.2f - i * %f\n", nb1, nb3, nb2 / nb3);
	printf("\033[0m");
}

void		solver_deg2_ezero(double a, double b)
{
	double		alpha;

	alpha = -(b / 2 * a);
	printf("\t\t\tDelta is = 0.\n");
	printf("\t\t\tThis equation has one solution in R :\n");
	printf("\t\t\t\t--> alpha = -(b / 2 * a)\n");
	printf("\t\t\t\033[1;32malpha = %f\n\033[0m", alpha);
}

void		solver_deg2_szero(double a, double b, double delta)
{
	double		x1;
	double		x2;

	x1 = (-b + ft_sqrt(delta)) / (2 * a);
	x2 = (-b - ft_sqrt(delta)) / (2 * a);
	printf("\t\t\tDelta is > 0.\n");
	printf("\t\t\tThis equation has two solutions in R :\n");
	printf("\t\t\t\t--> x1 = (-b + sqrt(delta)) / (2 * a)\n");
	printf("\t\t\t\t--> x2 = (-b - sqrt(delta)) / (2 * a)\n");
	printf("\t\t\t\033[1;32mx1 = %f\n\t\t\tx2 = %f\n\033[0m", x1, x2);
}

void		solver_deg2_nb(t_terme *lst, double *a, double *b, double *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
	while (lst)
	{
		if (ft_strequ(lst->b, "X^2"))
			*a = lst->a;
		else if (ft_strequ(lst->b, "X") || ft_strequ(lst->b, "X^1"))
			*b = lst->a;
		else if (!lst->b || ft_strequ(lst->b, "X^0"))
			*c = lst->a;
		lst = lst->next;
	}
}

int			solver_deg2(t_terme *lst)
{
	double		a;
	double		b;
	double		c;
	double		delta;

	solver_deg2_nb(lst, &a, &b, &c);
	delta = (b * b) - (4 * a * c);
	printf("\tQuadratic of form : a * X^2 + b * X + c = 0\n");
	printf("\t\t\tHere, a = %3.2f, b = %3.2f and c = %3.2f\n", a, b, c);
	printf("\t\t\tDelta is : %3.0f\t(b^2 - 4 * a * c)\n", delta);
	if (delta > 0)
		solver_deg2_szero(a, b, delta);
	else if (delta < 0)
		solver_deg2_izero(a, b, delta);
	else
		solver_deg2_ezero(a, b);
	return (1);
}
