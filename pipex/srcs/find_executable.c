/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:44:39 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/14 18:54:05 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*join_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
}

char	*find_executable(char *cmd, char **envp)
{
	char	*path;
	char	**dirs;
	char	*full;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	path = get_path(envp);
	if (!path)
		return (NULL);
	dirs = ft_split(path, ':');
	if (!dirs)
		return (NULL);
	i = 0;
	while (dirs[i])
	{
		full = join_path(dirs[i], cmd);
		if (full && access(full, X_OK) == 0)
			return (free_matrix(dirs), full);
		free(full);
		i++;
	}
	free_matrix(dirs);
	return (NULL);
}
