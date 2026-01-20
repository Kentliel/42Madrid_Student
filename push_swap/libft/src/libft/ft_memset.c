/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:36:55 by kcarrero          #+#    #+#             */
/*   Updated: 2025/05/05 20:16:00 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (n != 0)
	{
		p[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
int	main(void)
{
	char	buffer[10];

	ft_memset(buffer, 'A', 5);
	buffer[5] = '\0';
	printf("ft_memset result: %s\n", buffer);
	return (0);
}*/
