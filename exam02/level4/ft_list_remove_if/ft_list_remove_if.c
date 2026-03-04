/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:45:49 by kcarrero          #+#    #+#             */
/*   Updated: 2026/03/04 12:17:10 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*cur;
	t_list	*tmp;

	if (!begin_list || !cmp)
		return ;
	cur = *begin_list;
	while (cur && cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		cur = *begin_list;
	}
	while (cur && cur->next)
	{
		if (cmp(cur->next->data, data_ref) == 0)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			free(tmp);
		}
		else
			cur = cur->next;
	}
}
