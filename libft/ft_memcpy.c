/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:03:40 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/09 17:25:56 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*dep;
	const char		*sp;
	int				i;

	dep = dest;
	sp = src;
	i = 0;
	while (n != 0)
	{
		dep[i] = sp[i];
		i++;
		n--;
	}
	return (dest);
}
