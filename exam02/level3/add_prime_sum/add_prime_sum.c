/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:27:35 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/28 15:40:59 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int c)
{
	char	result;

	if (c >= 10)
		ft_putnbr(c / 10);
	result = (c % 10) + '0';
	write(1, &result, 1);
}

int	atoi_positive(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!str[i])
		return (-1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result <= 0)
		return (-1);
	return (result);
}

int	ft_is_prime(int n)
{
	int	i;

	if (n < 2)
		return (0);
	if (n == 2)
		return (1);
	if (n % 2 == 0)
		return (0);
	i = 3;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	number;
	int	sum;

	if (argc != 2)
	{
		write(1, "0", 1);
		return (write(1, "\n", 1));
	}
	number = atoi_positive(argv[1]);
	if (number < 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	sum = 0;
	i = 2;
	while (i <= number)
	{
		if (ft_is_prime(i))
			sum += i;
		i++;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}
