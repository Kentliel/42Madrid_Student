/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:23:16 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/12 15:31:19 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation_finished(t_table *table)
{
	int	finished;

	pthread_mutex_lock(&table->state_mutex);
	finished = table->simulation_end;
	pthread_mutex_unlock(&table->state_mutex);
	return (finished);
}

void	set_simulation_end(t_table *table)
{
	pthread_mutex_lock(&table->state_mutex);
	table->simulation_end = 1;
	pthread_mutex_unlock(&table->state_mutex);
}

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	if (!simulation_finished(philo->table))
		printf("%ld %d %s\n",
			timestamp_ms(philo->table->start_time), philo->id, msg);
	pthread_mutex_unlock(&philo->table->print_mutex);
}
