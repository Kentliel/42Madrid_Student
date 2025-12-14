/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:10:10 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/14 19:14:04 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include "libft.h"
# include "ft_printf.h"
# include <mlx.h>

//Keys for linux
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_map
{
	char	**grid;
	char	*raw_buf;
	int		width;
	int		height;
	int		count_p;
	int		count_c;
	int		count_e;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		tiles_s;
	int		moves;
	int		collect_left;
	void	*wall;
	void	*floor;
	void	*collect;
	void	*exit;
	void	*p_up;
	void	*p_down;
	void	*p_left;
	void	*p_right;
	void	*player_curr;
}	t_game;

typedef struct s_bfs
{
	int	x;
	int	y;
}	t_bfs;

typedef struct s_queue
{
	int	head;
	int	tail;
}	t_queue;

/*funcion utils_file.c*/
char	*ft_read_file(const char *path);
int		ft_check_extension(const char *path, const char *ext);

/*funcion utils_split.c*/
char	**ft_split_lines(char *s, int *out);

/*funcion parser_checks.c*/
int		ft_check_rectangular(t_map *m);
int		ft_check_borders(t_map *m);
int		ft_check_chars_and_counts(t_map *m);

/*funcion parser_path.c*/
int		ft_check_path_valid(t_map *m);

/*funcion parser_main.c*/
int		ft_parse_map(const char *path, t_map *map);
int		ft_print_error(char *msg);
void	ft_free_map(t_map *map);

/*Funcion init_game.c*/
void	ft_init_game(t_game *g, t_map *map);
int		ft_close_game(t_game *g);

/*Funcion render_map.c*/
int		ft_render_map(t_game *g);

/*Funcion game_move.c*/
void	ft_move_player(t_game *g, int dx, int dy);

/*Funcion game_images.c*/
int		ft_load_images(t_game *g);
void	ft_free_images(t_game *g);

#endif
