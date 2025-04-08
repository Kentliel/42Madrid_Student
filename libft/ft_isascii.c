/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:07:50 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/08 18:15:58 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ascii(unsigned char c)
{
	return (c >= 0 && c <= 127);
}

int	ft_isascii(int n)
{
	unsigned char	c;

	c = (unsigned char)n;
	return (ft_ascii(c));
}
