/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:14:47 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/11 18:23:56 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static void	ft_push_valid(t_map *m, int **v, t_bfs *q, t_queue *qi)
{
	int			i;
	t_bfs		next;
	t_bfs		curr;
	const int	dx[] = {0, 0, 1, -1};
	const int	dy[] = {1, -1, 0, 0};

	curr = q[(*qi).head];
	i = -1;
	while (++i < 4)
	{
		next.x = curr.x + dx[i];
		next.y = curr.y + dy[i];
		if (next.x >= 0 && next.y >= 0 && next.x < (*m).width
			&& next.y < (*m).height && !v[next.y][next.x]
			&& (*m).grid[next.y][next.x] != '1')
		{
			v[next.y][next.x] = 1;
			q[(*qi).tail] = next;
			(*qi).tail++;
		}
	}
}

static int	ft_cleanup_bfs(t_map *m, int **v, t_bfs *q)
{
	int	i;
	int	j;
	int	valid;

	valid = 1;
	i = 0;
	while (i < (*m).height)
	{
		j = 0;
		while (j < (*m).width)
		{
			if (((*m).grid[i][j] == 'C' || (*m).grid[i][j] == 'E') && !v[i][j])
				valid = 0;
			j++;
		}
		free(v[i++]);
	}
	free(v);
	free(q);
	if (!valid)
		ft_printf("ERROR\nPATH NOT VALID\n");
	return (valid);
}

static int	**ft_init_visited(t_map *m)
{
	int	**v;
	int	i;

	v = malloc(sizeof(int *) * (*m).height);
	if (!v)
		return (NULL);
	i = 0;
	while (i < (*m).height)
	{
		v[i] = ft_calloc((*m).width, sizeof(int));
		if (!v[i])
		{
			while (--i >= 0)
				free(v[i]);
			free(v);
			return (NULL);
		}
		i++;
	}
	return (v);
}

int	ft_check_path_valid(t_map *m)
{
	int		**v;
	t_bfs	*q;
	t_queue	qi;

	v = ft_init_visited(m);
	q = malloc(sizeof(t_bfs) * ((*m).width * (*m).height));
	if (!v || !q)
		return (0);
	qi.head = 0;
	qi.tail = 0;
	q[qi.tail].x = (*m).player_x;
	q[qi.tail].y = (*m).player_y;
	qi.tail++;
	v[(*m).player_y][(*m).player_x] = 1;
	while (qi.head < qi.tail)
	{
		ft_push_valid(m, v, q, &qi);
		qi.head++;
	}
	return (ft_cleanup_bfs(m, v, q));
}
