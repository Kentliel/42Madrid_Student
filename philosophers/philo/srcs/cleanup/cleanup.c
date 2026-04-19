/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:42:46 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/19 15:48:35 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_all(t_table *table)
{
	int	i;

	if (table->philos)
	{
		i = 0;
		while (i < table->nb_philos)
		{
			pthread_mutex_destroy(&table->philos[i].meal_mutex);
			i++;
		}
		free(table->philos);
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
