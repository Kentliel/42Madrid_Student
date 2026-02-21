/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:30:37 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/21 15:54:52 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	look;
	int	repeat;
	int	seen;

	if (argc != 3)
		return (write(1, "\n", 1));
	i = 0;
	while (argv[1][i])
	{
		seen = 0;
		repeat = 0;
		while (repeat < i)
		{
			if (argv[1][repeat] == argv[1][i])
				seen = 1;
			repeat++;
		}
		if (!seen)
		{
			look = 0;
			while (argv[2][look])
			{
				if (argv[1][i] == argv[2][look])
				{
					write(1, &argv[1][i], 1);
					break;
				}
				look++;
			}
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
