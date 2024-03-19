/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:39:18 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/19 19:33:03 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**clone_tab(char **tab)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!tab)
		return (NULL);
	while (tab[j])
		j++;
	res = malloc(sizeof(char *) * (j + 1));
	if (!res)
		return (res);
	res[j] = NULL;
	j = 0;
	while (tab[j])
	{
		res[j] = malloc(sizeof(char) * ft_strlen(tab[j]) + 1);
		res[j][ft_strlen(tab[j])] = 0;
		ft_memcpy(res[j], tab[j], ft_strlen(tab[j]));
		j++;
	}
	return (res);
}
