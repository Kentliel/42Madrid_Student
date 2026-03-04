/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:40:33 by kcarrero          #+#    #+#             */
/*   Updated: 2026/03/04 22:43:20 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	i;
	int	*arr;
	int	size;
	int	step;

	if (start > end)
	{
		size = start - end + 1;
		step = 1;
	}
	else
	{
		size = end - start + 1;
		step = -1;
	}
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = end;
		end = end + step;
		i++;
	}
	return (arr);
}
