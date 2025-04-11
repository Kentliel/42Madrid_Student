/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:51:11 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/11 13:03:31 by kcarrero         ###   ########.fr       */
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
