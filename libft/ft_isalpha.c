/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:30:04 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/08 17:56:58 by kcarrero         ###   ########.fr       */
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

int	ft_isallpha(int n)
{
	unsigned char	c;

	c = (unsigned char)n;
	return (ft_isupper(c) || ft_islower(c));
}
