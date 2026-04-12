/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:08:11 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/12 15:18:50 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

long	timestamp_ms(long start_time)
{
	return (get_time_ms() - start_time);
}

void	precise_sleep(t_table *table, long duration_ms)
{
	long	start;

	start = get_time_ms();
	while (!simulation_finished(table))
	{
		if (get_time_ms() - start >= duration_ms)
			break ;
		usleep(200);
	}
}
