/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:10:22 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/19 15:42:09 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_died(t_philo *philo)
{
	long	last_meal;
	long	now;

	pthread_mutex_lock(&philo->meal_mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->meal_mutex);
	now = get_time_ms();
	if ((now - last_meal) > philo->table->time_to_die)
		return (1);
	return (0);
}

static int	print_death(t_table *table, int i)
{
	pthread_mutex_lock(&table->print_mutex);
	pthread_mutex_lock(&table->state_mutex);
	table->simulation_end = 1;
	pthread_mutex_unlock(&table->state_mutex);
	printf("%ld %d died\n",
		timestamp_ms(table->start_time), table->philos[i].id);
	pthread_mutex_unlock(&table->print_mutex);
	return (1);
}

int	all_ate_enough(t_table *table)
{
	int	i;
	int	meals;

	if (table->must_eat_count == -1)
		return (0);
	i = 0;
	while (i < tabla->nb_philo)
	{
		pthread_mutex_lock(&table->philos[i].meal_mutex);
		meals = table->philos[i].meals_eaten;
		pthread_mutex_unlock(&table->philos[i].meal_mutex);
		if (meals < table->must_eat_count)
			return (0);
		i++;
	}
	return (1);
}

int	monitor_loop(t_table *table)
{
	int	i;

	while (!simulation_finished(table))
	{
		i = 0;
		while (i < table->nb_philos)
		{
			if (philo_died(&table->philos[i]))
				return (print_death(table, i));
			i++;
		}
		if (all_ate_enough(table))
		{
			set_simualtion_end(table);
			return (0);
		}
		usleep(500);
	}
	return (0);
}

int	start_simulation(t_table *table)
{
	int	i;

	table->start_time = get_time_ms();
	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL
				philo_routine, &table->philos[i]) != 0)
			return (1);
		i++;
	}
	monitor_loop(table);
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	return (0);
}
