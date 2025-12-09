/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:37:22 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/15 13:44:39 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int n)
{
	unsigned char	c;

	c = (unsigned char)n;
	if (n < 0 || n > 255)
		return (n);
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
