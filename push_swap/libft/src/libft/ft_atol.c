/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:30:19 by kcarrero          #+#    #+#             */
/*   Updated: 2026/01/30 00:57:22 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_spaces(const char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

static void	set_sign(const char *str, int *i, long *sign)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

static int	check_overflow(long result, int sign, int digit)
{
	if (result > (LONG_MAX - digit) / 10)
	{
		if (sign == 1)
			return (1);
		return (-1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	long	sign;
	int		i;
	int		ov;

	result = 0;
	sign = 1;
	i = skip_spaces(str);
	set_sign(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		ov = check_overflow(result, sign, str[i] - '0');
		if (ov == 1)
			return (LONG_MAX);
		if (ov == -1)
			return (LONG_MIN);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
