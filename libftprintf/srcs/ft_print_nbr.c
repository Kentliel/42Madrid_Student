/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:41:19 by kcarrero          #+#    #+#             */
/*   Updated: 2025/05/17 18:48:16 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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
