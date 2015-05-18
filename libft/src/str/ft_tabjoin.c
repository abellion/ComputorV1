/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 14:38:55 by abellion          #+#    #+#             */
/*   Updated: 2015/03/23 18:16:27 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	**tab_join(char **tab1, char **tab2)
{
	char	**new_tab;
	char	*tmp;
	int		len_new_tab;
	int		count;
	int		index;

	len_new_tab = ft_tablen(tab1) + ft_tablen(tab2) + 1;
	new_tab = (char **)malloc(sizeof(char *) * len_new_tab);
	if (!tab1 || !tab2 || !new_tab)
		return (0);
	index = 0;
	count = 0;
	while (count < (len_new_tab - 1))
	{
		if (tab1 && !tab1[index])
		{
			tab1 = NULL;
			index = 0;
		}
		tmp = (tab1) ? tab1[index] : tab2[index];
		new_tab[count] = ft_strdup(tmp);
		index++, count++;
	}
	new_tab[count] = NULL;
	return (new_tab);
}
