/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:05:53 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/15 13:25:50 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	ft_print_error(char *msg)
{
	ft_printf("ERROR\n%s\n", msg);
	return (0);
}

void	ft_free_map(t_map *map)
{
	if (!map)
		return ;
	if ((*map).raw_buf)
	{
		free((*map).raw_buf);
		(*map).raw_buf = NULL;
	}
	if ((*map).grid)
	{
		free((*map).grid);
		(*map).grid = NULL;
	}
}

static int	ft_check_basic(t_map *map)
{
	if (!ft_check_rectangular(map))
		return (ft_print_error("Mapa no rectangular"));
	if (!ft_check_borders(map))
		return (ft_print_error("Mapa no cerrado"));
	if (!ft_check_chars_and_counts(map))
		return (ft_print_error("Caracteres invalidos en el mapa"));
	if ((*map).count_p != 1)
		return (ft_print_error("Debe haber exactamente 1 jugador ('P')"));
	if ((*map).count_e != 1)
		return (ft_print_error("Debe haber exactamente 1 salida ('E')"));
	if ((*map).count_c < 1)
		return (ft_print_error("Debe haber al menos 1 coleccionable ('C')"));
	return (1);
}

static int	ft_setup_map_grid(const char *path, t_map *map)
{
	char	*buf;
	int		lines;

	buf = ft_read_file(path);
	if (!buf)
		return (ft_print_error("No se pudo leer el fichero"));
	(*map).grid = ft_split_lines(buf, &lines);
	(*map).raw_buf = NULL;
	if (!(*map).grid || lines == 0)
	{
		free(buf);
		return (ft_print_error("Mapa vacio o fallo al dividir lineas"));
	}
	(*map).raw_buf = buf;
	(*map).height = lines;
	(*map).width = ft_strlen((*map).grid[0]);
	(*map).count_p = 0;
	(*map).count_c = 0;
	(*map).count_e = 0;
	return (1);
}

int	ft_parse_map(const char *path, t_map *map)
{
	if (!ft_check_extension(path, ".ber"))
		return (ft_print_error("Extension incorrecta (.ber)"));
	if (!ft_setup_map_grid(path, map))
		return (0);
	if (!ft_check_basic(map))
	{
		ft_free_map(map);
		return (0);
	}
	ft_printf("✅ Mapa valido (%dx%d)\n", (*map).width, (*map).height);
	return (1);
}
