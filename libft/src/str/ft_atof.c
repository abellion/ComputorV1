/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 18:24:46 by abellion          #+#    #+#             */
/*   Updated: 2015/03/23 22:08:26 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static double	ft_pow(double base, double exponent)
{
	double		result;

	if (exponent == 0)
		return (1);
	else if (exponent < 0)
		return (0);
	result = base;
	while (exponent - 1)
	{
		result *= base;
		exponent--;
	}
	return (result);
}

double			ft_atof(const char *str)
{
	char		**splits;
	double		after;
	double		result;

	if (!str)
		return (0);
	splits = ft_strsplit(str, '.');
	result = ft_atoi(splits[0]);
	after = ft_atoi(splits[1]);
	after /= ft_pow(10, ft_strlen(splits[1]));
	after = (str[0] == '-') ? after * -1 : after;
	return (result + after);
}
