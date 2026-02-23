/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2_mult.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 01:04:14 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/23 01:06:36 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int	p;

	if (n == 0)
		return (0);
	p = 1;
	while (p < n)
		p = p * 2;
	if (p == n)
		return (1);
	return (0);
}
