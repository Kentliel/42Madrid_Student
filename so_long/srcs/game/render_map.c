/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:05:46 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/14 19:16:15 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_img(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window((*g).mlx, (*g).win, img,
		x * (*g).tiles_s, y * (*g).tiles_s);
}

/*Draw a square of a specific color pixel by pixel*/
static void	ft_draw_tile(t_game *g, int x, int y)
{
	char	c;

	c = (*g).map.grid[y][x];
	ft_put_img(g, (*g).floor, x, y);
	if (c == '1')
		ft_put_img(g, (*g).wall, x, y);
	else if (c == 'C')
		ft_put_img(g, (*g).collect, x, y);
	else if (c == 'E')
		ft_put_img(g, (*g).exit, x, y);
	else if (c == 'P')
		ft_put_img(g, (*g).player_curr, x, y);
}

static void	ft_draw_moves(t_game *g)
{
	char	*nbr;

	mlx_string_put((*g).mlx, (*g).win, 12, 20, 0xFFFFFF, "Moves: ");
	nbr = ft_itoa((*g).moves);
	if (nbr)
	{
		mlx_string_put((*g).mlx, (*g).win, 60, 20, 0xFFFFFF, nbr);
		free(nbr);
	}
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
			ft_draw_tile(g, x, y);
			x++;
		}
		y++;
	}
	ft_draw_moves(g);
	return (0);
}
