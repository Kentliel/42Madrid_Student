/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:10:10 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/11 19:32:47 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include "libft.h"

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
void	ft_free_map(t_map *map);

#endif
