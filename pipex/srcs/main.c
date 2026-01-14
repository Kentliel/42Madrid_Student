/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:10:41 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/14 20:44:02 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	open_files(char **argv, t_pipex *px)
{
	px->in_fd = open(argv[1], O_RDONLY);
	if (px->in_fd == -1)
	{
		perror(argv[1]);
		exit(1);
	}
	px->out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (px->out_fd == -1)
	{
		perror(argv[4]);
		if (px->in_fd != -1)
			close(px->in_fd);
		exit(1);
	}
}

static pid_t	launch(char *cmd, t_pipex *px, int in, int out)
{
	px->in_fd = in;
	px->out_fd = out;
	return (create_child(cmd, px));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;
	int		status;

	if (argc != 5)
		return (ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n"), 1);
	px.envp = envp;
	open_files(argv, &px);
	if (pipe(px.pipe_fd) == -1)
		return (perror("pipe"), 1);
	px.close_fd = px.pipe_fd[0];
	px.pip1 = launch(argv[2], &px, px.in_fd, px.pipe_fd[1]);
	px.close_fd = px.pipe_fd[1];
	px.pip2 = launch(argv[3], &px, px.pipe_fd[0], px.out_fd);
	close(px.in_fd);
	close(px.out_fd);
	close(px.pipe_fd[0]);
	close(px.pipe_fd[1]);
	waitpid(px.pip1, NULL, 0);
	waitpid(px.pip2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
