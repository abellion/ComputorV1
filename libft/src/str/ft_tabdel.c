/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 16:32:17 by abellion          #+#    #+#             */
/*   Updated: 2015/03/23 16:45:19 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_tabdel(char ***tab)
{
	int		index;

	index = 0;
	if (tab && *tab)
	{
		while ((*tab)[index])
		{
			ft_strdel(&(*tab)[index]);
			index++;
		}
		free(*tab);
		*tab = NULL;
	}
}
