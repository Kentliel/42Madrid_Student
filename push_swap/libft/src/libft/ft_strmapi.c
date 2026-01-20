/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:38:29 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/27 22:45:34 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result_str;
	size_t	s_len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	result_str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!result_str)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		result_str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	result_str[i] = '\0';
	return (result_str);
}
