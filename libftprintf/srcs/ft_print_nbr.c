/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:41:19 by kcarrero          #+#    #+#             */
/*   Updated: 2025/05/24 16:44:29 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_nbr(int n)
{
	char	*num;
	int		len;

	num = ft_itoa(n);
	len = ft_strlen(num);
	write(1, num, len);
	free(num);
	return (len);
}
