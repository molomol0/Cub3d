/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:39:18 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/20 21:29:27 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**clone_tab(char **tab)
{
	char	**res;
	int		j;

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
