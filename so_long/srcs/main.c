/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:59:05 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/14 00:12:42 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!ft_parse_map(argv[1], &map))
		return (1);
	ft_init_game(&game, &map);
	ft_render_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
