/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:05:07 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/14 19:12:17 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*close the game cleanly*/
int	ft_close_game(t_game *g)
{
	ft_free_images(g);
	if ((*g).win)
		mlx_destroy_window((*g).mlx, (*g).win);
	if ((*g).mlx)
	{
		mlx_destroy_display((*g).mlx);
		free((*g).mlx);
	}
	ft_free_map(&(*g).map);
	exit(0);
	return (0);
}

/*Detects the ESC key*/
static int	ft_key_hook(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		ft_close_game(g);
	else if (keycode == KEY_W)
		ft_move_player(g, 0, -1);
	else if (keycode == KEY_A)
		ft_move_player(g, -1, 0);
	else if (keycode == KEY_S)
		ft_move_player(g, 0, 1);
	else if (keycode == KEY_D)
		ft_move_player(g, 1, 0);
	return (0);
}

/*g->title_s(tamaño P. de cuadrado), hook (1(window x button), 2(keyboard))*/
void	ft_init_game(t_game *g, t_map *map)
{
	(*g).tiles_s = 64;
	(*g).map = *map;
	(*g).moves = 0;
	(*g).collect_left = (*g).map.count_c;
	(*g).mlx = mlx_init();
	if (!(*g).mlx)
	{
		ft_free_map(map);
		exit(1);
	}
	if (!ft_load_images(g))
	{
		free((*g).mlx);
		ft_free_map(map);
		exit(1);
	}
	(*g).win = mlx_new_window((*g).mlx, (*g).map.width * (*g).tiles_s,
			(*g).map.height * (*g).tiles_s, "so_long");
	if (!(*g).win)
		ft_close_game(g);
	mlx_hook((*g).win, 17, 0, ft_close_game, g);
	mlx_key_hook((*g).win, ft_key_hook, g);
}
