/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:38:40 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/09 11:06:58 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_char(t_map *m, char c, int x, int y)
{
	if (c == 'P')
	{
		(*m).count_p++;
		(*m).player_x = x;
		(*m).player_y = y;
	}
	else if (c == 'C')
		(*m).count_c++;
	else if (c == 'E')
		(*m).count_e++;
	else if (c != '0' && c != '1')
		return (0);
	return (1);
}

int	check_rectangular(t_mapp *m)
{
	int	i;

	i = 0;
	while (i < (*m).height)
	{
		if ((int)ft_strlen((*m).grid[i]) != (*m).width)
			return (0);
		i++;
	}
	return (1);
}

int	check_borders(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	while (x < (*m).width)
	{
		if ((*m).grid[0][x] != '1' || (*m).grid[(*m).height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < (*m).height)
	{
		if ((*m).grid[y][0] != '1' || (*m).grid[y][(*m).width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_chars_and_counts(t_map *m)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < (*m).height)
	{
		x = 0;
		while (x < (*m).width)
		{
			if (!validate_char(m, (*m).grid[y][x], x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
