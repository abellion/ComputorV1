/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:29:51 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 17:59:05 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_pow(double base, double exponent)
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

double		ft_sqrt(double x)
{
	int			counter;
	double		result;

	counter = 0;
	while (counter++ <= x)
		counter *= counter;
	result = counter;
	while (counter--)
		result = 0.5 * result + 0.5 * (x / result);
	return (result);
}
