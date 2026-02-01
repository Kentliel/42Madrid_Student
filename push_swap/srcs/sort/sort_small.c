/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 00:16:02 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/01 21:44:15 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_stack *stack)
{
	if (stack->a->value > stack->a->next->value)
		sa(stack, 1);
}

static void	sort_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->value;
	b = stack->a->next->value;
	c = stack->a->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack, 1);
	else if (a > b && b > c)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack, 1);
}

static int	min_index_pos(t_node *a)
{
	int	pos;
	int	min;
	int	i;

	pos = 0;
	min = a->index;
	i = 0;
	while (a)
	{
		if (a->index < min)
		{
			min = a->index;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

static void	push_min_to_b(t_stack *stack)
{
	int	pos;
	int	rot;

	pos = min_index_pos(stack->a);
	if (pos <= stack->size_a / 2)
	{
		while (pos-- > 0)
			ra(stack, 1);
	}
	else
	{
		rot = stack->size_a - pos;
		while (rot-- > 0)
			rra(stack, 1);
	}
	pb(stack, 1);
}

void	sort_small(t_stack *stack)
{
	if (stack->size_a == 2)
		sort_2(stack);
	else if (stack->size_a == 3)
		sort_3(stack);
	else
	{
		while (stack->size_a > 3)
			push_min_to_b(stack);
		sort_3(stack);
		while (stack->size_b > 0)
			pa(stack, 1);
	}
}
