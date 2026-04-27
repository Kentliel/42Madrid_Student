/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:23:16 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/27 15:19:11 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Lee de forma segura si la simulacion ha terminado
 * Devuelve 1 si termino, 0 en caso contrario*/
int	simulation_finished(t_table *table)
{
	int	finished;

	pthread_mutex_lock(&table->state_mutex);
	finished = table->simulation_end;
	pthread_mutex_unlock(&table->state_mutex);
	return (finished);
}

/*Marca la simulacion como terminada de forma segura*/
void	set_simulation_end(t_table *table)
{
	pthread_mutex_lock(&table->state_mutex);
	table->simulation_end = 1;
	pthread_mutex_unlock(&table->state_mutex);
}

/*Imprime el estado de un filosofo si la simulacion no termino
 * protege la comprobacion del estado y la impresion con mutex*/
void	print_status(t_philo *philo, char *msg)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->state_mutex);
	if (table->simulation_end)
	{
		pthread_mutex_unlock(&table->state_mutex);
		return ;
	}
	pthread_mutex_unlock(&table->state_mutex);
	pthread_mutex_lock(&table->print_mutex);
	printf("%ld %d %s\n",
		timestamp_ms(philo->table->start_time), philo->id, msg);
	pthread_mutex_unlock(&table->print_mutex);
}
