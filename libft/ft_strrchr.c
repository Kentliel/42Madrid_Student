/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:43:19 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/16 16:09:44 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	char_c;
	char	*last_position;
	size_t	i;

	char_c = (char)c;
	last_position = NULL;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == char_c)
			last_position = (char *)&s[i];
		i++;
	}
	if (char_c == '\0')
		return ((char *)&s[i]);
	return (last_position);
}
