/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:05:46 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/12 13:44:47 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Draw a square of a specific color pixel by pixel*/
static void	ft_draw_square(t_game *g, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*g).tiles_s)
	{
		j = 0;
		while (j < (*g).tiles_s)
		{
			mlx_pixel_put((*g).mlx, (*g).win, (x * (*g).tiles_s) + j,
				(y * (*g).tiles_s) + i, color);
			j++;
		}
		i++;
	}
}

static void	ft_put_pixel_color(t_game *g, int x, int y)
{
	char	c;

	c = (*g).map.grid[y][x];
	if (c == '1')
		ft_draw_square(g, x, y, 0x808080);
	else if (c == '0')
		ft_draw_square(g, x, y, 0xFFFFFF);
	else if (c == 'P')
		ft_draw_square(g, x, y, 0x00FF00);
	else if (c == 'C')
		ft_draw_square(g, x, y, 0xFFFF00);
	else if (c == 'E')
		ft_draw_square(g, x, y, 0x0000FF);
}

int	ft_render_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*g).map.height)
	{
		x = 0;
		while (x < (*g).map.width)
		{
			ft_put_pixel_color(g, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
