/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:11:15 by kcarrero          #+#    #+#             */
/*   Updated: 2026/03/04 23:14:16 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	tmp;
	unsigned int	gcd;
	unsigned int	a_copy;
	unsigned int	b_copy;

	if (a == 0 || b == 0)
		return (0);
	a_copy = a;
	b_copy = b;
	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	gcd = a;
	return ((a_copy * b_copy) / gcd);
}
