/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:09:05 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/30 13:36:13 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_number(t_stack *stack, char *str)
{
	long	value;
	t_node	*new;

	if (!is_number(str))
		error_exit(stack, "Error\n");
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
		error_exit(stack, "Error\n");
	new = stack_new((int)value);
	if (!new)
		error_exit(stack, "Error\n");
	stack_add_back(&stack->a, new);
	stack->size_a++;
}

static int	invalid_args(char *str)
{
	int	i;

	if (!str || !str[0])
		return (1);
	if (ft_isspace(str[0]))
		return (1);
	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	parse_args(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	**split;
	int		j;

	i = 1;
	while (i < argc)
	{
		if (invalid_args(argv[i]))
			error_exit(stack, "Error\n");
		split = ft_split(argv[i], ' ');
		if (!split)
			error_exit(stack, "Error\n");
		j = 0;
		while (split[j])
		{
			if (split[j])
				add_number(stack, split[j]);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	if (is_duplicates(stack->a))
		error_exit(stack, "Error\n");
}
