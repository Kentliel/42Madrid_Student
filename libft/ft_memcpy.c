/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:03:40 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/10 14:08:19 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*dep;
	const unsigned char		*sp;
	size_t					i;

	dep = (unsigned char *)dest;
	sp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dep[i] = sp[i];
		i++;
	}
	return (dest);
}
