/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:35:37 by kcarrero          #+#    #+#             */
/*   Updated: 2026/04/27 15:10:03 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Comprueba que la cadena contiene solo digitos y no esta vacia
 * devuelve 1 si es valida, 0 en caso contrario*/
static int	is_digit_str(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*COnvierte una cadena decimal positica a long
 * comprueba que la cadena sea numerica y que no supere INT_MAX
 * Escribe el resultado en *result
 * Devuelve 0 si Ok, 1 en caso de error*/
int	ft_atoi_positive(const char *str, long *result)
{
	long	num;
	int		i;

	if (!is_digit_str(str))
		return (1);
	num = 0;
	i = 0;
	while (str[i])
	{
		num = (num * 10) + (str[i] - '0');
		if (num > 2147483647)
			return (1);
		i++;
	}
	*result = num;
	return (0);
}

/*Valida y asigna los argumentos de linea de comandos a la tabla
 * formato esperado: nb_philos time_to_die time_to_eat time_to_sleep
 * opcional: must_eat_count
 * devuelve 0 si OK, 1 en caso de error*/
int	parse_args(t_table *table, int ac, char **av)
{
	long	value;

	if (ac != 5 && ac != 6)
		return (printf("Error: wrong number of argumentes\n"), 1);
	if (ft_atoi_positive(av[1], &value) != 0 || value <= 0)
		return (printf("Error: invalid number_of_philosophers\n"), 1);
	table->nb_philos = (int)value;
	if (ft_atoi_positive(av[2], &table->time_to_die) != 0
		|| table->time_to_die <= 0)
		return (printf("Error: invalid time_to_die\n"), 1);
	if (ft_atoi_positive(av[3], &table->time_to_eat) != 0
		|| table->time_to_eat <= 0)
		return (printf("Error: invalid time_to_eat\n"), 1);
	if (ft_atoi_positive(av[4], &table->time_to_sleep) != 0
		|| table->time_to_sleep <= 0)
		return (printf("Error: invalid time_to_sleep"), 1);
	if (ac == 6)
	{
		if (ft_atoi_positive(av[5], &value) != 0 || value <= 0)
			return (printf("Error: invalid must_eat_count\n"), 1);
		table->must_eat_count = (int)value;
	}
	return (0);
}
