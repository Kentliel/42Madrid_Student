/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:47:56 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/01 13:44:12 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (0);
	init_stack(&stack);
	parse_args(argc, argv, &stack);
	if (is_sorted(stack.a))
	{
		free_stack(&stack.a);
		return (0);
	}
	index_stack(&stack);
	if (stack.size_a <= 5)
		sort_small(&stack);
	else
		chunk_sort(&stack);
	free_stack(&stack.a);
	free_stack(&stack.b);
	return (0);
}
