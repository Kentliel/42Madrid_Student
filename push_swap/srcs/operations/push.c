/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 23:22:07 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/29 23:28:18 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_node(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_stack *stack, int	print)
{
	if (!stack->b)
		return ;
	push_node(&stack->b, &stack->a);
	stack->size_b--;
	stack->size_a++;
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack *stack, int	print)
{
	if (!stack->a)
		return ;
	push_node(&stack->a, &stack->b);
	stack->size_a--;
	stack->size_b++;
	if (print)
		ft_printf("pb\n");
}
