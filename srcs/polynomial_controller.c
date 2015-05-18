/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 16:39:14 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 20:25:27 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computor.h"

void	polynomial_put(float nb)
{
	char	*name;

	printf("\033[0;32mPolynomial type : \033[0m\t");
	if ((name = polynomial_name(nb)))
		printf("%s (degree %d)\n", name, (int)nb);
	else
		printf("\033[0;31mNot a Polynomial function.\033[0m\n");
	ft_strdel(&name);
}

char	*polynomial_name(float nb)
{
	char	*names[11];

	if (nb < 0 || nb > 10 || nb != (int)nb)
		return (0);
	names[0] = "Constant";
	names[1] = "Linear";
	names[2] = "Quadratic";
	names[3] = "Cubic";
	names[4] = "Quartic";
	names[5] = "Quintic";
	names[6] = "Sextic";
	names[7] = "Septic";
	names[8] = "Octic";
	names[9] = "Nonic";
	names[10] = "Decic";
	return (ft_strdup(names[(int)nb]));
}

float	polynomial_controller(t_terme *termes)
{
	float		exponent;
	char		**splits;

	exponent = -1;
	splits = NULL;
	if (termes)
		splits = ft_strsplit(termes->b, '^');
	if (splits && splits[0] && splits[1])
		exponent = ft_atof(splits[1]);
	else if (splits && splits[0] && ft_strequ(splits[0], "X"))
		exponent = 1;
	else if (termes && !termes->b)
		exponent = 0;
	return (exponent);
}
