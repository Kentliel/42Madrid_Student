/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:57:45 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/15 11:41:35 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static char	*ft_append_chunk(char *buf, char *tmp, ssize_t r)
{
	char	*new_buf;
	size_t	len;

	if (r <= 0)
		return (buf);
	len = 0;
	if (buf)
		len = ft_strlen(buf);
	new_buf = malloc(len + (size_t)r +1);
	if (!new_buf)
	{
		free(buf);
		return (NULL);
	}
	if (buf)
		ft_memcpy(new_buf, buf, len);
	ft_memcpy(new_buf + len, tmp, (size_t)r);
	new_buf[len + (size_t)r] = '\0';
	free(buf);
	return (new_buf);
}

static char	*read_into_buf(int fd)
{
	ssize_t	r;
	char	tmp[4096];
	char	*buf;

	buf = ft_calloc(1, 1);
	if (!buf)
		return (NULL);
	r = read(fd, tmp, sizeof(tmp));
	while (r > 0)
	{
		buf = ft_append_chunk(buf, tmp, r);
		if (!buf)
			return (NULL);
		r = read(fd, tmp, sizeof(tmp));
	}
	if (r < 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

int	ft_check_extension(const char *path, const char *ext)
{
	size_t	p;
	size_t	e;

	p = ft_strlen(path);
	e = ft_strlen(ext);
	if (p <= e)
		return (0);
	return (!ft_strncmp(path + p - e, ext, e));
}

char	*ft_read_file(const char *path)
{
	int		fd;
	char	*buf;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = read_into_buf(fd);
	close(fd);
	return (buf);
}
