/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:35:15 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/10 22:47:46 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printascii(unsigned char c)
{
	return ((c >= 32 && c <= 126));
}

int	ft_isprint(int n)
{
	unsigned char	c;

	c = (unsigned char)n;
	return (ft_printascii(c));
}
