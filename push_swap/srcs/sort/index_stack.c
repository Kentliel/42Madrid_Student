/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 00:00:52 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/01 12:19:37 by kcarrero         ###   ########.fr       */
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

static void	fill_array(t_node *a, int *arr)
{
	int	i;

	i = 0;
	while (a)
	{
		arr[i++] = a->value;
		a = a->next;
	}
}

static void	assign_indexes(t_node *a, int *arr, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->value == arr[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

void	index_stack(t_stack *stack)
{
	int		*arr;

	arr = (int *)malloc(sizeof(int) * stack->size_a);
	if (!arr)
		error_exit(stack, "Error\n");
	fill_array(stack->a, arr);
	sort_array(arr, stack->size_a);
	assign_indexes(stack->a, arr, stack->size_a);
	free(arr);
}
