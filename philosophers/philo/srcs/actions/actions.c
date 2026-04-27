/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:42:52 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/27 14:42:04 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*bloque dos tenedores en un orden que evita deadlock
 * devuelve 0 si el bloqueo ambos tenedores, 1 termina la simulacion*/
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

/*Gestiona la accion de tomar tenedores
 * caso de nb_philos == 1: code el unico tenedor y espera hata time_to_die
 * devuelve 0 si consiguio tenedores, 1 si no puede comer o simulacion acabo*/
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

/*Actualiza el estado de la comida, simula el tiempo de comer y libera tenedor
 * Protege last_meal y meals_eaten con meal_mutex*/
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

/*Imprime estado y duerme el tiempo configurado*/
void	sleep_action(t_philo *philo)
{
	print_status(philo, "is sleeping");
	precise_sleep(philo->table, philo->table->time_to_sleep);
}

/*Imprime que el filosofo esta pensando*/
void	think_action(t_philo *philo)
{
	print_status(philo, "is thinking");
}
