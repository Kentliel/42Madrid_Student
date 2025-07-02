/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:19:27 by kcarrero          #+#    #+#             */
/*   Updated: 2025/06/20 19:26:15 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_and_update_cache(int fd, int *finished)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(buffer), NULL);
	buffer[bytes_read] = '\0';
	if (bytes_read == 0)
	{
		*finished = 1;
		return (free(buffer), NULL);
	}
	return (buffer);
}

static char	*ft_read_and_cache(int fd, char *cache)
{
	int		finished;
	char	*buffer;
	char	*tmp;

	finished = 0;
	while (!ft_strchr_gnl(cache, '\n') && !finished)
	{
		buffer = ft_read_and_update_cache(fd, &finished);
		if (finished == 0 && !buffer)
			return (free(cache), NULL);
		if (!buffer)
			return (cache);
		if (!cache)
			cache = ft_strdup_gnl(buffer);
		else
		{
			tmp = ft_strjoin_gnl(cache, buffer);
			free(cache);
			cache = tmp;
		}
		free(buffer);
		if (!cache || ft_strlen_gnl(cache) == 0)
			return (free(cache), NULL);
	}
	return (cache);
}

static char	*ft_extract_line(char *cache)
{
	int		i;
	char	*line;

	if (!cache || !cache[0])
		return (NULL);
	i = 0;
	while (cache[i] && cache[i] != '\n')
		i++;
	if (cache[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_memcpy_gnl(line, cache, i);
	line[i] = '\0';
	return (line);
}

static char	*ft_update_cache(char *cache)
{
	char	*new_cache;
	int		i;
	int		cache_len;

	if (!cache)
		return (NULL);
	i = 0;
	while (cache[i] && cache[i] != '\n')
		i++;
	if (!cache[i])
		return (free(cache), NULL);
	i++;
	cache_len = ft_strlen_gnl(cache);
	new_cache = (char *)malloc(sizeof(char) * (cache_len - i + 1));
	if (!new_cache)
		return (free(cache), NULL);
	ft_memcpy_gnl(new_cache, cache + i, cache_len - i);
	new_cache[cache_len - i] = '\0';
	free(cache);
	return (new_cache);
}

char	*get_next_line(int fd)
{
	static char	*cache[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	cache[fd] = ft_read_and_cache(fd, cache[fd]);
	if (!cache[fd])
	{
		free(cache[fd]);
		cache[fd] = NULL;
		return (NULL);
	}
	line = ft_extract_line(cache[fd]);
	if (!line)
	{
		free(cache[fd]);
		cache[fd] = NULL;
		return (NULL);
	}
	cache[fd] = ft_update_cache(cache[fd]);
	return (line);
}
