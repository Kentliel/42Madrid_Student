/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:54:55 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/15 08:56:56 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	redirect_io(t_pipex *px)
{
	int	tmp;

	if (px->in_fd == -1)
	{
		tmp = open("/dev/null", O_RDONLY);
		if (tmp == -1)
		{
			perror("open /dev/null");
			return (-1);
		}
		px->in_fd = tmp;
	}
	if (dup2(px->in_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 stdin");
		return (-1);
	}
	if (dup2(px->out_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 stdout");
		return (-1);
	}
	close(px->in_fd);
	close(px->out_fd);
	return (0);
}

void	execute_child(char *cmd, t_pipex *px)
{
	char	**args;
	char	*exec;

	if (redirect_io(px) == -1)
		exit(1);
	args = parse_command(cmd);
	exec = find_executable(args[0], px->envp);
	if (!exec)
	{
		ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
		ft_putendl_fd(args[0], STDERR_FILENO);
		free_matrix(args);
		exit(127);
	}
	execve(exec, args, px->envp);
	perror("execve");
	free(exec);
	free_matrix(args);
	exit(127);
}

pid_t	create_child(char *cmd, t_pipex *px)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		if (px->in_fd == px->pipe_fd[0])
			close(px->pipe_fd[1]);
		else if (px->out_fd == px->pipe_fd[1])
			close(px->pipe_fd[0]);
		execute_child(cmd, px);
	}
	return (pid);
}
