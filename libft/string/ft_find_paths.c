/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:53:10 by jdenis           #+#    #+#             */
/*   Updated: 2023/08/08 16:05:37 by jdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**find_paths(char **envp)
{
	int		index;
	char	**paths;

	index = 0;
	while (envp[index])
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[index] + 5, ':');
			return (paths);
		}
		index++;
	}
	return (NULL);
}
