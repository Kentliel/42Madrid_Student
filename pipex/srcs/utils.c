/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:40:56 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/15 13:16:47 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_command(char *cmd)
{
	char	**args;

	if (cmd == NULL)
	{
		perror("parse_command");
		exit(1);
	}
	args = ft_split(cmd, ' ');
	if (args == NULL)
	{
		perror("malloc");
		exit(1);
	}
	if (args[0] == NULL || args[0][0] == '\0')
	{
		free_matrix(args);
		perror("parse_command");
		exit(1);
	}
	return (args);
}

void	free_matrix(char **m)
{
	int	i;

	if (!m)
		return ;
	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}
