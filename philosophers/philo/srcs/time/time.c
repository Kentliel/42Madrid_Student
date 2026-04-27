/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:08:11 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/27 15:16:27 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Devuelve el tiempo actual en milisegundos*/
long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

/*Devuelve los milisegundos transcurridos desde start_time*/
long	timestamp_ms(long start_time)
{
	return (get_time_ms() - start_time);
}

/*Duerme de forma precisa durante duration_ms o hasta que termine la simulacion
 *comprueba periodicamente simulation_finished para poder interrumpir el sueño*/
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
