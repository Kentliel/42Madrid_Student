/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:42:33 by kcarrero          #+#    #+#             */
/*   Updated: 2025/05/05 19:43:37 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	const char	*str1 = "42Madrid";
	const char	*str2 = "";

	printf("ft_strlen (\"%s\") = %lu\n", str1, ft_strlen(str1));
	printf("ft_strlen (\"\") = %lu\n", ft_strlen(str2));
	return (0);
}*/
