/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:32:27 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/01 13:55:10 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

static void	push_to_b_by_chunks(t_stack *stack, int chunk)
{
	int	current;

	current = 0;
	while (stack->size_a > 0)
	{
		if (stack->a->index <= current)
		{
			pb(stack, 1);
			rb(stack, 1);
			current++;
		}
		else if (stack->a->index <= current + chunk)
		{
			pb(stack, 1);
			current++;
		}
		else
			ra(stack, 1);
	}
}

static void	bring_max_to_top_b(t_stack *stack, int max)
{
	int	pos;

	pos = get_pos_of_index(stack->b, max);
	if (pos < 0)
		return ;
	if (pos <= stack->size_b / 2)
	{
		while (stack->b && stack->b->index != max)
			rrb(stack, 1);
	}
}

static void	push_back_to_a(t_stack *stack)
{
	int	max;

	while (stack->size_b > 0)
	{
		max = find_max_index(stack->b);
		bring_max_to_top_b(stack, max);
		pa(stack, 1);
	}
}

void	chunk_sort(t_stack *stack)
{
	int	chunk;

	chunk = get_chunk_size(stack->size_a);
	push_to_b_by_chunks(stack, chunk);
	push_back_to_a(stack);
}
