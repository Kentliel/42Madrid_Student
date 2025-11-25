#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_map
{
	char	**grid;
	char	*raw_buf;
	int	width;
	int	height;
	int	count_p;
	int count_c;
	int	count_e;
	int	player_x;
	int	player_y;
}	t_map;

int	ft_parse_map(const char *path, t_map *map);
void	ft_free_map(t_map *map);

char	*ft_read_file(const char *path);
char	**ft_split_lines(char *s, int *out_lines);
int	ft_check_extension(const char *path, const char *ext);
size_t	ft_strlen(const char *s);

int	ft_check_rectangular(t_map *m);
int	ft_check_borders(t_map *m);
int	ft_check_chars_and_counts(t_map *m);
int	ft_check_path_valid(t_map *m);

#endif
