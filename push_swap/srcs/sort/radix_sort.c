/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 00:30:59 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/30 00:37:04 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	max_bits = 0;
	size = stack->size_a;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack->a->index >> i) & 1) == 1)
				ra(stack, 1);
			else
				pb(stack, 1);
			j++;
		}
		while (stack->size_b > 0)
			pa(stack, 1);
		i++;
	}
}
