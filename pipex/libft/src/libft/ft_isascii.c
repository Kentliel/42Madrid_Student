/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:07:50 by kcarrero          #+#    #+#             */
/*   Updated: 2025/05/05 19:22:50 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ascii(unsigned char c)
{
	return (c <= 127);
}

int	ft_isascii(int n)
{
	unsigned char	c;

	if (n < 0 || n > 255)
		return (0);
	else
	{
		c = (unsigned char)n;
		return (ft_ascii(c));
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int	c;

	c = 65;
	printf("ft_isascii ('%c') = %d\n", c,  ft_isascii(c));
	c = 128;
	printf("ft_isascii (%d) = %d\n", c, ft_isascii(c));
	return (0);
}*/
