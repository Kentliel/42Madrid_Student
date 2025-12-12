/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:57:45 by kcarrero          #+#    #+#             */
/*   Updated: 2025/12/12 13:16:35 by kcarrero         ###   ########.fr       */
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

	len = 0;
	if (buf)
		len = ft_strlen(buf);
	new_buf = malloc(len + r +1);
	if (!new_buf)
	{
		free(buf);
		return (NULL);
	}
	if (buf)
		ft_memcpy(new_buf, buf, len);
	ft_memcpy(new_buf + len, tmp, r);
	new_buf[len + r] = '\0';
	free(buf);
	return (new_buf);
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
	ssize_t	r;
	char	*buf;
	char	tmp[4096];

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = ft_calloc(1, 1);
	if (!buf)
		return (NULL);
	r = read(fd, tmp, sizeof(tmp));
	while (r > 0)
	{
		buf = ft_append_chunk(buf, tmp, r);
		if (!buf)
		{
			close(fd);
			return (NULL);
		}
		r = read(fd, tmp, sizeof(tmp));
	}
	close(fd);
	return (buf);
}
