/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:42:46 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/27 14:46:02 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Destruye mutexes y libera memoria asociada a la mesa*/
void	destroy_all(t_table *table)
{
	int	i;

	if (table->philo)
	{
		i = 0;
		while (i < table->nb_philos)
		{
			pthread_mutex_destroy(&table->philo[i].meal_mutex);
			i++;
		}
		free(table->philo);
	}
	if (table->forks)
	{
		i = 0;
		while (i < table->nb_philos)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		free(table->forks);
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->state_mutex);
}
