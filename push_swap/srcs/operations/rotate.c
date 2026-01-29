/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:32:01 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/29 23:38:55 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = stack_last(*stack);
	last->next = first;
}

void	ra(t_stack *stack, int print)
{
	rotete_stack(&stack->a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack *stack, int print)
{
	rotate_stack(&stack->b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack *stack, int print)
{
	rotate_stack(&stack->a);
	rotate_stack(&stack->b);
	if (print)
		ft_printf("rr\n");
}
