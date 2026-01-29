/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:39:45 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/29 23:45:45 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack *stack, int print)
{
	reverse_rotate_stack(&stack->a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack *stack, int print)
{
	reverse_rotate_stack(&stack->b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack *stack, int print)
{
	reverse_rotate_stack(&stack->a);
	reverse_rotate_stack(&stack->b);
	if (print)
		ft_printf("rrr\n");
}
