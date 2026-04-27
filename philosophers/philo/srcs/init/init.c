/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:36:13 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/27 14:58:05 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Reserva e inicializa los mutex de los tenedores
 * devuelve 0 si todo Ok, 1 en caso de error*/
static int	init_forks(t_table *table)
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

/*Inicializa mutexes globales y crea el array de filosofos
 * devuelve 0 si todo ok, 1 en caso de fallo*/
int	init_table(t_table *table)
{
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->state_mutex, NULL) != 0)
		return (1);
	if (init_forks(table) != 0)
		return (1);
	table->philo = malloc(sizeof(t_philo) * table->nb_philos);
	if (!table->philo)
		return (1);
	return (0);
}

/*Inicializa cada filosofo: id, tenedores, contadores y mutex de comida
 * devuelve 0 si todo OK, si falla la inicializacion de algun mutex*/
int	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		table->philo[i].id = i + 1;
		table->philo[i].left_fork = i;
		table->philo[i].right_fork = (i + 1) % table->nb_philos;
		table->philo[i].meals_eaten = 0;
		table->philo[i].last_meal = 0;
		table->philo[i].table = table;
		if (pthread_mutex_init(&table->philo[i].meal_mutex, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
