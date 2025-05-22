/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:59:13 by kcarrero          #+#    #+#             */
/*   Updated: 2025/05/22 23:40:49 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	ft_put_ptr(unsigned long long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_put_ptr(n / 16);
	write(1, &base[n % 16], 1);
}

static int	ft_ptr_len(unsigned long long n)
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

int	ft_print_ptr(void *ptr)
{
	unsigned long long	addres;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addres = (unsigned long long)ptr;
	write(1, "0x", 2);
	ft_put_ptr(addres);
	return (ft_ptr_len(addres) + 2);
}
