/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:59:05 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/15 11:58:33 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_map_struct(t_map *map)
{
	ft_bzero(map, sizeof(*map));
	(*map).player_x = -1;
	(*map).player_y = -1;
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
	{
		ft_printf("ERROR\nUso: ./so_long <mapa.ber>\n");
		return (1);
	}
	map.count_c = 0;
	map.count_p = 0;
	map.count_e = 0;
	map.grid = NULL;
	map.raw_buf = NULL;
	ft_init_map_struct(&map);
	if (!ft_parse_map(argv[1], &map))
	{
		ft_free_map(&map);
		return (1);
	}
	ft_init_game(&game, &map);
	ft_render_map(&game);
	mlx_loop(game.mlx);
	ft_free_map(&map);
	return (0);
}
