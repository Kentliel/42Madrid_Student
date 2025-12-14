/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:38:40 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/14 01:00:10 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_validate_char(t_map *m, char c, int x, int y)
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

int	ft_check_rectangular(t_map *m)
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

int	ft_check_borders(t_map *m)
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

int	ft_check_chars_and_counts(t_map *m)
{
	int		x;
	int		y;

	y = 0;
	while (y < (*m).height)
	{
		x = 0;
		while (x < (*m).width)
		{
			if (!ft_validate_char(m, (*m).grid[y][x], x, y))
				return (0);
			x++;
		}
		y++;
	}
	if ((*m).count_c < 1)
		return (ft_print_error("ERROR EN EL DEBUG: La variable C es 0"));
	if ((*m).count_p != 1)
		return (ft_print_error("Debe haber 1 punto de inicio ('P')"));
	if ((*m).count_e < 1)
		return (ft_print_error("Debe haber al menos 1 salida ('E')"));
	return (1);
}
