/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:32:42 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/14 15:47:00 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_valid_move(t_game *g, int x, int y)
{
	if ((*g).map.grid[y][x] == '1')
		return (0);
	if ((*g).map.grid[y][x] == 'E' && (*g).collect_left > 0)
		return (0);
	return (1);
}

static void	ft_process_cell(t_game *g, int x, int y)
{
	if ((*g).map.grid[y][x] == 'C')
	{
		(*g).collect_left--;
		(*g).map.grid[y][x] = '0';
	}
	if ((*g).map.grid[y][x] == 'E' && (*g).collect_left == 0)
	{
		ft_printf("🎉 ¡Ganaste en %d movimientos!\n", (*g).moves + 1);
		ft_close_game(g);
	}
}

void	ft_move_player(t_game *g, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = (*g).map.player_x + dx;
	ny = (*g).map.player_y + dy;
	if (!ft_valid_move(g, nx, ny))
		return ;
	ft_process_cell(g, nx, ny);
	if ((*g).map.grid[ny][nx] != 'E')
	{
		(*g).map.grid[(*g).map.player_y][(*g).map.player_x] = '0';
		(*g).map.grid[ny][nx] = 'P';
		(*g).map.player_x = nx;
		(*g).map.player_y = ny;
		(*g).moves++;
		ft_printf("Movimientos: %d\n", (*g).moves);
		ft_render_map(g);
	}
}
