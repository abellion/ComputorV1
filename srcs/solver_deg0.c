/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_deg0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 20:25:34 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 20:30:03 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/computor.h"

int		solver_deg0(t_terme *lst)
{
	printf("\tIn all cases, the result will not change.\n");
	printf("\t\t\t\033[1;32m%3.2f\n\033[0m", lst->a);
	return (0);
}
