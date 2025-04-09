/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:36:55 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/09 15:26:55 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	int				i;

	p = s;
	i = 0;
	while (n != 0)
	{
		p[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (s);
}
