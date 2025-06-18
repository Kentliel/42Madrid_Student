/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:23:06 by kcarrero          #+#    #+#             */
/*   Updated: 2025/06/16 22:48:54 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strdup_gnl(const char *s);
char	*ft_strchr_gnl(const char *s, int c);
void	*ft_memcpy_gnl(void *dest, const void *src, size_t n);
size_t	ft_strlen_gnl(const char *s);

#endif
