/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:10:41 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/15 09:07:48 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	open_files(char **argv, t_pipex *px)
{
	px->in_fd = open(argv[1], O_RDONLY);
	if (px->in_fd == -1)
		perror(argv[1]);
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

static int	collect_exit_status(pid_t pid1, pid_t pid2)
{
	int	status1;
	int	status2;

	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status1) && WEXITSTATUS(status1) != 0)
		return (WEXITSTATUS(status1));
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;
	int		outfile_fd;

	if (argc != 5)
		return (ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n"), 1);
	px.envp = envp;
	open_files(argv, &px);
	outfile_fd = px.out_fd;
	if (pipe(px.pipe_fd) == -1)
		return (perror("pipe"), 1);
	px.pid1 = launch(argv[2], &px, px.in_fd, px.pipe_fd[1]);
	px.pid2 = launch(argv[3], &px, px.pipe_fd[0], outfile_fd);
	close(px.pipe_fd[0]);
	close(px.pipe_fd[1]);
	if (px.in_fd != -1)
		close(px.in_fd);
	close(outfile_fd);
	return (collect_exit_status(px.pid1, px.pid2));
}
