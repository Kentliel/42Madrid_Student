/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 21:16:45 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/17 21:38:42 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	putnbr(int c)
{
	char	result;

	if (c >= 10)
		putnbr(c / 10);
	result = (c % 10) + '0';
	write(1, &result, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "0", 1);
		return (write(1, "\n", 1));
	}
	putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}
