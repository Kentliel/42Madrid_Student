/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:10:22 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/27 15:04:52 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Comprueba si un filosofo ha superado time_to_die desde su ultima comida
 * devuelve 1 si murio, 0 en caso contrario*/
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

/*Imprime el mensaje de muerte y marca la simulacion como terminada
 * devuelve 1 siempre que se detecte o intente marcar el fin*/
static int	print_death_and_end(t_table *table, int i)
{
	int	already_end;

	pthread_mutex_lock(&table->print_mutex);
	already_end = table->simulation_end;
	if (!already_end)
		table->simulation_end = 1;
	pthread_mutex_unlock(&table->state_mutex);
	if (already_end)
		return (1);
	pthread_mutex_lock(&table->state_mutex);
	printf("%ld %d died\n",
		timestamp_ms(table->start_time), table->philo[i].id);
	pthread_mutex_unlock(&table->print_mutex);
	return (1);
}

/*Comprueba si todos los filosofos han comido al menos must_eat_count veces
 * devuelve 1 si todos cumplieron, 0 si no o si must_eat_count == -1*/
int	all_ate_enough(t_table *table)
{
	int	i;
	int	meals;

	if (table->must_eat_count == -1)
		return (0);
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_lock(&table->philo[i].meal_mutex);
		meals = table->philo[i].meals_eaten;
		pthread_mutex_unlock(&table->philo[i].meal_mutex);
		if (meals < table->must_eat_count)
			return (0);
		i++;
	}
	return (1);
}

/*Bucle que vigila la simulacion: detecta muertes y comprueba condicion de fin
 * devuelve 0 en finalizacion normal, 1 si detecta muerte*/
int	monitor_loop(t_table *table)
{
	int	i;

	while (!simulation_finished(table))
	{
		i = 0;
		while (i < table->nb_philos)
		{
			if (philo_died(&table->philo[i]))
				return (print_death_and_end(table, table->philo[i].id));
			i++;
		}
		if (all_ate_enough(table))
		{
			set_simulation_end(table);
			return (0);
		}
		usleep(500);
	}
	return (0);
}

/*Inicializa tiempos y lanza hilos de filosofos, luegos ejecuta el monitor
 * devuelve 0 si todo OK, 1 si falla la creacion de algun hilo*/
int	start_simulation(t_table *table)
{
	int	i;

	table->start_time = get_time_ms();
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_lock(&table->philo[i].meal_mutex);
		table->philo[i].last_meal = table->start_time;
		pthread_mutex_unlock(&table->philo[i].meal_mutex);
		if (pthread_create(&table->philo[i].thread, NULL,
				philo_routine, &table->philo[i]) != 0)
			return (1);
		i++;
	}
	monitor_loop(table);
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
	return (0);
}
