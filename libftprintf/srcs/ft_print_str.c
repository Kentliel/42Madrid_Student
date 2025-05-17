/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:51:18 by kcarrero          #+#    #+#             */
/*   Updated: 2025/05/17 17:58:40 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_print_str(char *str)
{
	int	len;

	if (!str)
		return (write(1, "(Null)", 6));
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
