/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:20:47 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/10 22:28:49 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*sp;
	int				i;

	i = 0;
	sp = (unsigned char *)s;
	while (n != 0)
	{
		sp[i] = '\0';
		i++;
		n--;
	}
}
