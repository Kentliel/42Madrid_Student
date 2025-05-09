/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:30:04 by kcarrero          #+#    #+#             */
/*   Updated: 2025/05/05 17:50:43 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(unsigned char c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	ft_islower(unsigned char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isalpha(int n)
{
	unsigned char	c;

	if (n < 0 || n > 255)
	{
		return (0);
	}
	else
	{
		c = (unsigned char)n;
		return (ft_isupper(c) || ft_islower(c));
	}
}
/*
#include <stdio.h>
int	main(void)
{
	printf("ft_isalpha ('A') = %d\n", ft_isalpha('A'));
	printf("ft_isalpha ('z') = %d\n", ft_isalpha('z'));
	printf("ft_isalpha ('1') = %d\n", ft_isalpha('1'));
	printf("ft_isalpha ('$') = %d\n", ft_isalpha('$'));
	return (0);
}*/
