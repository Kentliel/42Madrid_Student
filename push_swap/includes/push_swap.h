/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:03:40 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/20 13:57:16 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*Structures*/

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
}	t_stack;

/*Parsing*/

void	parse_args(int argc, char **argv, t_stack *stack);
int		is_number(char *str);
int		has_duplicates(t_node *a);
void	free_and_exit(t_node **a, char *msg);

/*Stacks*/

void	stack_add_back(t_node **stack, t_node *new_node);
t_node	*stack_new(int value);
t_node	*stack_last(t_node *stack);
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);

/*Operations*/

//Swap
void	sa(t_stack *stack, int print);
void	sb(t_stack *stack, int print);
void	ss(t_stack *stack, int print);

//Push
void	pa(t_stack *stack, int print);
void	pb(t_stack *stack, int print);

//Rotate
void	ra(t_stack *stack, int print);
void	rb(t_stack *stack, int print);
void	rr(t_stack *stack, int print);

void	rra(t_stack *stack, int print);
void	rrb(t_stack *stack, int print);
void	rrr(t_stack *stack, int print);

/*Sorting Algorithm*/

//Small Case
void	index_stack(t_stack *stack);
void	sort_small(t_stack *stack);

//Radix
void	radix_sort(t_stack *stack);

/*Utils*/

void	free_stack(t_node **stack);
void	error_exit(t_stack *stack, char *msg);

#endif
