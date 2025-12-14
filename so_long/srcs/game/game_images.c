/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:27:10 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/14 18:54:42 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_load(t_game *g, char *path)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image((*g).mlx, path, &w, &h);
	if (!img)
	{
		ft_printf("Error\nNo se pudo cargar la imagen: %s\n", path);
		return (NULL);
	}
	if (w != (*g).tiles_s || h != (*g).tiles_s)
	{
		ft_printf("Error\nDimensiones incorrectas en: %s\n");
		mlx_destroy_image((*g).mlx, img);
		return (NULL);
	}
	return (img);
}

int	ft_load_images(t_game *g)
{
	(*g).wall = ft_load(g, "textures/wall_tree.xpm");
	(*g).floor = ft_load(g, "textures/floor_game.xpm");
	(*g).collect = ft_load(g, "textures/collect_game.xpm");
	(*g).exit = ft_load(g, "textures/exit_game.xpm");
	(*g).p_down = ft_load(g, "textures/player_front.xpm");
	(*g).p_up = ft_load(g, "textures/player_back.xpm");
	(*g).p_right = ft_load(g, "textures/player_right.xpm");
	(*g).p_left = ft_load(g, "textures/player_left.xpm");
	(*g).player_curr = (*g).p_down;
	if (!(*g).wall || !(*g).floor || !(*g).collect || !(*g).exit
		|| !(*g).p_down || !(*g).p_up || !(*g).p_right || !(*g).p_left)
		return (0);
	return (1);
}

void	ft_free_images(t_game *g)
{
	if ((*g).wall)
		mlx_destroy_image((*g).mlx, (*g).wall);
	if (g->floor)
		mlx_destroy_image(g->mlx, g->floor);
	if (g->collect)
		mlx_destroy_image(g->mlx, g->collect);
	if (g->exit)
		mlx_destroy_image(g->mlx, g->exit);
	if (g->p_down)
		mlx_destroy_image(g->mlx, g->p_down);
	if (g->p_up)
		mlx_destroy_image(g->mlx, g->p_up);
	if (g->p_right)
		mlx_destroy_image(g->mlx, g->p_right);
	if (g->p_left)
		mlx_destroy_image(g->mlx, g->p_left);
}
