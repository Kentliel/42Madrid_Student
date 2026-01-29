/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:08:43 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/29 23:17:30 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_nodes(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack *stack, int print)
{
	swap_nodes(&stack->a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack *stack, int print)
{
	swap_nodes(&stack->b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack *stack, int print)
{
	swap_nodes(&stack->a);
	swap_nodes(&stack->b);
	if (print)
		ft_printf("ss\n");
}
