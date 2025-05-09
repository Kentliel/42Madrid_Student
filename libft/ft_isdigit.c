/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:51:11 by kcarrero          #+#    #+#             */
/*   Updated: 2025/05/05 18:20:24 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number(unsigned char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isdigit(int n)
{
	unsigned char	c;

	if (n < 0 || n > 255)
	{
		return (0);
	}
	else
	{
		c = (unsigned char)n;
		return (ft_number(c));
	}
}
/*
#include <stdio.h>
int	main(void)
{
	printf("ft_isdigit (2) = %d\n", ft_isdigit(2));
	printf("ft_isdigit ('A') = %d\n", ft_isdigit('A'));
	printf("ft_isdigit ('$') = %d\n", ft_isdigit('$'));
	return (0);
}*/
