/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 01:07:40 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/23 01:19:39 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	max(int	*tab, unsigned int len)
{
	unsigned int	i;
	int		max_value;

	if (len == 0)
		return (0);
	max_value = tab[0];
	i = 1;
	while (i < len)
	{
		if (max_value < tab[i])
			max_value = tab[i];
		i++;
	}
	return (max_value);
}
