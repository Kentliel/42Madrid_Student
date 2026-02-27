/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:27:35 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/26 15:36:01 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	atoi(*str)
{
	int	i;
	int	result;
	int	signo;

	i = 0;
	signo = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) && (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * signo);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (write(1, "\n", 1));
	
}
