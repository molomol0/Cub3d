/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:01:36 by jdenis            #+#    #+#             */
/*   Updated: 2024/03/18 15:31:25 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*res;
// 	size_t	res_len;

// 	if (!s)
// 		return (NULL);
// 	if (ft_strlen(s) < start)
// 	{
// 		res = malloc(sizeof(char));
// 		res[0] = 0;
// 		if (!res)
// 			return (NULL);
// 	}
// 	else
// 	{
// 		res_len = ft_strlen(s + start);
// 		if (!(res_len < len))
// 			res_len = len;
// 		res = (char *)malloc((res_len + 1) * sizeof(char));
// 		if (!res)
// 			return (NULL);
// 		res[res_len] = 0;
// 		while (res_len-- > 0)
// 			res[res_len] = s[start + res_len];
// 	}
// 	return (res);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*res;
// 	int		i;
// 	int		j;

// 	i = ft_strlen(s1);
// 	j = ft_strlen(s2);
// 	res = malloc((i + j + 1) * sizeof(char));
// 	if (!res || !s1 || !s2)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		res[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	res[i] = 0;
// 	return (res);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 		{
// 			return ((char *)(s + i));
// 		}
// 		i++;
// 	}
// 	if (s[i] == c)
// 	{
// 		return ((char *)(s + i));
// 	}
// 	return (NULL);
// }
