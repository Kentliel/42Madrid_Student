/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:52:12 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/15 15:56:26 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int n)
{
	unsigned char	c;

	c = (unsigned char)n;
	if (n < 0 || n > 255)
		return (n);
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
