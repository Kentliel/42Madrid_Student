/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:45:13 by kcarrero          #+#    #+#             */
/*   Updated: 2026/03/04 22:50:19 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int	start, int end)
{
	int	i;
	int	*arr;
	int	size;
	int	step;

	if (start > end)
	{
		size = start - end + 1;
		step = -1;
	}
	else
	{
		size = end - start + 1;
		step = 1;
	}
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = start;
		start = start + step;
		i++;
	}
	return (arr);
}
