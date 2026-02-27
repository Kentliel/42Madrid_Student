/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:15:39 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/27 14:37:04 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;
	t_list	*current;

	count = 0;
	current = begin_list;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
