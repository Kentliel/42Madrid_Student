/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:26:55 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/14 20:42:31 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		close_fd;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**envp;
}	t_pipex;

/*child_process.c*/
void	execute_child(char *cmd, t_pipex *px);
pid_t	create_child(char *cmd, t_pipex *px);

/*find_executable.c*/
char	*find_executable(char *cmd, char **envp);

/*utils.c*/
char	**parse_command(char *cmd);
void	free_matrix(char **m);

#endif
