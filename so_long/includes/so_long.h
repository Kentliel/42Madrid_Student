#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include "libft.h"

typedef struct s_map
{
	char	**grid;
	char	*raw_buf;
	int	width;
	int	height;
	int	count_p;
	int	count_c;
	int	count_e;
	int	player_x;
	int	player_y;
}	t_map;

/*funcion utils_file.c*/
char	*ft_read_file(const char *path);
int	check_extension(const char *path, const char *ext);

/*funcion utils_split.c*/
char	**ft_split_lines(char *s, int *out);

/*funcion parser_checks.c*/
int	check_rectangular(t_map *m);
int	check_borders(t_map *m);
int	check_chars_and_counts(t_map *m);

/*funcion parser_path.c*/
int	check_path_valid(t_map *m);

/*funcion parser_main.c*/
int	parse_map(const char *path, t_map *map);
void	free_map(t_map *map);

#endif
