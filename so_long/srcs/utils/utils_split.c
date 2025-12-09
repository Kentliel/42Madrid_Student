/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:00:56 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/04 18:56:47 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static int	ft_count_lines(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			count++;
		i++;
	}
	if (i > 0 && s[i - 1] != '\n')
		count++;
	return (count);
}

static int	ft_fill_array(char *s, char **arr)
{
	int		index;
	char	*start;

	index = 0;
	start = s;
	while (*s)
	{
		if (*s == '\n')
		{
			*s = '\0';
			arr[index] = start;
			index++;
			start = s + 1;
		}
		s++;
	}
	if (*start)
	{
		arr[index] = start;
		index++;
	}
	arr[index] = NULL;
	return (index);
}

char	**ft_split_lines(char *s, int *out)
{
	char	**arr;
	int		len;

	if (!s || !out)
		return (NULL);
	len = ft_count_lines(s);
	arr = ft_calloc(len + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	*out = ft_fill_array(s, arr);
	return (arr);
}
