/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:26:24 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/20 01:08:06 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*static void	ft_putchar(int c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		ft_putchar(str[i]);
		i++;
	}
}*/

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	//t_list	*tmp;

	while (begin_list != NULL)
	{
		//tmp = begin_list;
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

/*int	main(void)
{
	t_list	list;
	char	*data = "hola";

	list = malloc(sizeof(t_list));
	list->data = malloc(sizeof(char) * 4 + 1);
	list->data = data;
	ft_list_foreach(list, ft_putstr(data));
	return (0);
}*/

// int	main(void)
// {
// 	t_list	*list;
// 	int	i;
// 	int	*data;

// 	list = malloc(sizeof(t_list));
// 	i = 99;
// 	while (i > 0)
// 	{
// 		data = malloc(sizeof(int));
// 		*data = i;
// 		list->data = data;
// 		i--;
// 	}
// 	ft_list_foreach(list);
// 	return (0);
// }

/*int main (void)
{
	t_list *list;
	t_list *head;
	int		i;
	char	*s = "hola";
	t_list *tmp;

	i = 4;
	head = malloc(sizeof(t_list));
	tmp = head;
	head->data = s;

	while (i > 0)
	{
		list = malloc(sizeof(t_list));
		list->data = s;
		head->next = list;
		head = head->next;
		i--;
	}
	ft_list_foreach(tmp);
	return (0);
}*/
