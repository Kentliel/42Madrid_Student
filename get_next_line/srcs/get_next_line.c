/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:19:27 by kcarrero          #+#    #+#             */
/*   Updated: 2025/06/18 19:02:46 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*ft_read_and_update_cache(int fd, char *cache, int *finished)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*tmp;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(buffer), free(cache), NULL);
	buffer[bytes_read] = '\0';
	if (bytes_read == 0)
		return (free(buffer), *finished = 1, cache);
	if (!cache)
		cache = ft_strdup_gnl(buffer);
	else
	{
		tmp = ft_strjoin_gnl(cache, buffer);
		free(cache);
		if (!tmp)
			return (free(buffer), NULL);
		cache = tmp;
	}
	return (free(buffer), cache);
}

static char	*ft_read_and_cache(int fd, char *cache)
{
	int	finished;

	finished = 0;
	while (!ft_strchr_gnl(cache, '\n') && !finished)
	{
		cache = ft_read_and_update_cache(fd, cache, &finished);
		if (!cache)
			return (NULL);
		if (ft_strlen_gnl(cache) == 0)
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
		return (NULL);
	ft_memcpy_gnl(new_cache, cache + i, cache_len - i);
	new_cache[cache_len - i] = '\0';
	free(cache);
	return (new_cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	cache = ft_read_and_cache(fd, cache);
	if (!cache)
		return (NULL);
	line = ft_extract_line(cache);
	cache = ft_update_cache(cache);
	return (line);
}
