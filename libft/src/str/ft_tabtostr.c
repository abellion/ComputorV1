/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 14:38:55 by abellion          #+#    #+#             */
/*   Updated: 2015/03/26 19:35:46 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_tabtostr(char **tab)
{
	char	*str;
	int		index;

	index = 0;
	str = NULL;
	while (tab && tab[index])
	{
		str = (!str) ? ft_strdup("") : str;
		str = ft_strjoin(str, tab[index]);
		index++;
	}
	return (str);
}
