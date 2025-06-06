/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:21:16 by kcarrero          #+#    #+#             */
/*   Updated: 2025/06/06 17:10:03 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy_gnl(void *dest, const void *src, size_t n)
{
	unsigned char		*dep;
	const unsigned char	*sp;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	dep = (unsigned char *)dest;
	sp = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dep[i] = sp[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup_gnl(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen_gnl(s);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_memcpy_gnl(dup, s, len);
	dup[len] = '\0';
	return (dup);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*join_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	total_len = s1_len + s2_len;
	join_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!join_str)
		return (NULL);
	ft_memcpy_gnl(join_str, s1, s1_len);
	ft_memcpy_gnl(join_str + s1_len, s2, s2_len);
	join_str[total_len] = '\0';
	return (join_str);
}
