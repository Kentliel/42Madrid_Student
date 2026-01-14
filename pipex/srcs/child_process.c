/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:54:55 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/14 19:01:26 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_child(char *cmd, t_pipex *px)
{
	char	**args;
	char	*exec;

	if (dup2(px->int_fd, STDIN_FILENO) == -1)
		exit(1);
	if (dup2(px->out_fd, STDOUT_FILENO) == -1)
		exit(1);
	args = parse_command(cmd);
	exec = find_executable(args[0], px->envp);
	if (!exec)
	{
		ft_printf("pipex: command not found %s\n", args[0]);
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
	if (pid == 0)
	{
		close(px->close_fd);
		execute_child(cmd, px);
	}
	return (pid);
}
