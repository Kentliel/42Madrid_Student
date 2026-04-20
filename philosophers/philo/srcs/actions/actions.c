/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:42:52 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/20 13:33:00 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	lock_forks_in_order(t_philo *philo)
{
	int	first;
	int	second;

	first = philo->left_fork;
	if (philo->id % 2 == 0)
		first = philo->right_fork;
	second = philo->left_fork + philo->right_fork - first;
	pthread_mutex_lock(&philo->table->forks[first]);
	if (simulation_finished(philo->table))
	{
		pthread_mutex_unlock(&philo->table->forks[first]);
		return (1);
	}
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->table->forks[second]);
	if (simulation_finished(philo->table))
	{
		pthread_mutex_unlock(&philo->table->forks[second]);
		pthread_mutex_unlock(&philo->table->forks[first]);
		return (1);
	}
	print_status(philo, "has taken a fork");
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (philo->table->nb_philos == 1)
	{
		pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
		print_status(philo, "has taken a fork");
		precise_sleep(philo->table, philo->table->time_to_die);
		pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
		return (1);
	}
	if (lock_forks_in_order(philo))
		return (1);
	return (0);
}

void	eat_action(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_status(philo, "is eating");
	precise_sleep(philo->table, philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
}

void	sleep_action(t_philo *philo)
{
	print_status(philo, "is sleeping");
	precise_sleep(philo->table, philo->table->time_to_sleep);
}

void	think_action(t_philo *philo)
{
	print_status(philo, "is thinking");
}
