/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:55:04 by kcarrero          #+#    #+#             */
/*   Updated: 2025/05/24 17:11:40 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_count_digits(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	char	buffer[11];
	int		len;
	int		i;

	len = ft_count_digits(n);
	buffer[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	write(1, buffer, len);
	return (len);
}
