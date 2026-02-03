/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:09:05 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/03 12:27:13 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_number(t_stack *stack, char *str)
{
	long	value;
	t_node	*new;

	if (!is_number(str))
		return (0);
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	new = stack_new((int)value);
	if (!new)
		return (0);
	stack_add_back(&stack->a, new);
	stack->size_a++;
	return (1);
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

static void	parse_one_arg(t_stack *stack, char *arg)
{
	char	**split;
	int		j;

	if (invalid_args(arg))
		error_exit(stack, "Error\n");
	split = ft_split(arg, ' ');
	if (!split)
		error_exit(stack, "Error\n");
	j = 0;
	while (split[j])
	{
		if (!add_number(stack, "Error\n"))
		{
			ft_free_split(split);
			error_exit(stack, "Error\n");
		}
		j++;
	}
	ft_free_split(split);
}

void	parse_args(int argc, char **argv, t_stack *stack)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		parse_one_arg(stack, argv[i]);
		i++;
	}
	if (is_duplicates(stack->a))
		error_exit(stack, "Error\n");
}
