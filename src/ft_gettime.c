/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:47:50 by ftholoza          #+#    #+#             */
/*   Updated: 2024/03/29 15:59:09 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

long	ft_gettime(long start)
{
	struct timeval	time;
	long			sres;
	long			ures;

	gettimeofday(&time, NULL);
	sres = (time.tv_sec);
	ures = (time.tv_usec);
	sres *= 1000;
	ures /= 1000;
	sres += ures;
	sres -= start;
	return (sres);
}

long	ft_get_start(void)
{
	struct timeval	time;
	long			sres;
	long			ures;

	gettimeofday(&time, NULL);
	sres = (time.tv_sec);
	ures = (time.tv_usec);
	ures /= 1000;
	sres *= 1000;
	sres += ures;
	return (sres);
}
