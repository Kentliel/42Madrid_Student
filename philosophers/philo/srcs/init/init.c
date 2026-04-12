/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:36:13 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/12 15:51:57 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	intit_forks(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philos);
	if (!table->forks)
		return (1);
	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	init_table(t_table *table)
{
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->state_mutex, NULL) != 0)
		return (1);
	if (init_forks(table) != 0)
		return (1);
	table->philos = malloc(sizeof(t_philo) * table->nb_philos);
	if (!table->philos)
		return (1);
	return (0);
}

int	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].left_fork = i;
		table->philos[i].right_fork = (i + 1) % table->nb_philos;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = 0;
		table->philos[i].table = table;
		if (pthread_mutex_init(&table->philos[i].meal_mutex, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
