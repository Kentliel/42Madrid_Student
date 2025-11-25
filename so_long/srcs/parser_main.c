/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:30:15 by kcarrero          #+#    #+#             */
/*   Updated: 2025/11/10 18:19:07 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_basic(t_map *map)
{
	if (!ft_check_rectangular(map))
		return (fprintf(stderr, "Error\n Non-rectangular map"), 0);
	if (!ft_check_borders(map))
		return (fprintf(stderr, "Error\n Unclosed map"), 0);
	if (!check_chars_and_counts(map))
		return (fprintf(stderr, "Error\nInvalid character"), 0);
	if (map->count_p != 1)
		return (fprintf(stderr. "Error\nThere must be exactly 1 'P'\n"), 0);
	if (map->count_c < 1 || map->count_e < 1)
		return (fprintf(stderr, "Error\nThere must be 'C' and 'E'\n"), 0);
	return (1);
}

int	ft_parse_map(const char	*path, t_map *map)
{
	char	*buf;
	int	line_count;

	if (!check_extension(path, ".ber"))
		return (fprintf(stderr, "Error\nIncorrect extension\n"), 0);
}
