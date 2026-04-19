/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:03:38 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/19 15:09:59 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = philo->table->start_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!simulation_finished(philo->table))
	{
		if (take_forks(philo))
			return (NULL);
		eat_action(philo);
		if (simulation_finished(philo->table))
			break ;
		sleep_action(philo);
		if (simulation_finished(philo->table))
			break ;
		think_action(philo);
	}
	return (NULL);
}
