/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 00:00:52 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/30 01:26:09 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int	*arr, int size)
{
	int	i;
	int	tmp;
	int	swapped;

	while (size > 1)
	{
		i = 0;
		swapped = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
		if (!swapped)
			break ;
		size--;
	}
}

void	index_stack(t_stack *stack)
{
	t_node	*tmp;
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * stack->size_a);
	if (!arr)
		error_exit(stack, "Error\n");
	tmp = stack->a;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	sort_array(arr, stack->size_a);
	tmp = stack->a;
	while (tmp)
	{
		i = 0;
		while (i < stack->size_a)
		{
			if (tmp->value == arr[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}
