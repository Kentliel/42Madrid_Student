/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:28:18 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/12 15:15:40 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_defaults(t_table *table)
{
	table->nb_philo = 0;
	table->time_to_die = 0;
	table->time_to_eat = 0;
	table->time_to_sleep = 0;
	table->must_eat_count = -1;
	table->simulation_end = 0;
	table->start_time = 0;
	table->forks = NULL;
	table->philos = NULL;
}

int	main(int ac, char **av)
{
	t_table	table;

	init_defaults(&table);
	if (parse_args(&table, ac, av) != 0)
		return (1);
	if (init_table(&table) != 0)
		return (1);
	if (init_philo(&table) != 0)
	{
		destroy_all(&table);
		return (1);
	}
	if (start_simulation(&table) != 0)
	{
		destroy_all(&table);
		return (1);
	}
	destroy_all(&table);
	return (0);
}
