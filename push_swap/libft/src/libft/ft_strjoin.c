/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:33:39 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/23 23:40:31 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	join_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!join_str)
		return (NULL);
	ft_memcpy(join_str, s1, s1_len);
	ft_memcpy(join_str + s1_len, s2, s2_len);
	join_str[total_len] = '\0';
	return (join_str);
}
