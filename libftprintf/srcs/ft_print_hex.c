/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:06:29 by kcarrero          #+#    #+#             */
/*   Updated: 2025/05/19 19:18:30 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_puthex(unsigned int n, char format)
{
	char	*base;

	if (format == 'x')
	{
		base = "0123456789abcdef";
	}
	else
	{
		base = "0123456789ABCDEF";
	}
	if (n >= 16)
		ft_puthex(n / 16, format);
	write(1, &base[n % 16], 1);
}

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_print_hex(unsigned int n, char format)
{
	ft_puthex(n, format);
	return (ft_hex_len(n));
}
