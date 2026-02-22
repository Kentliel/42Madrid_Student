/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:00:13 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/22 23:34:28 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_putchar(char c)
	write(1, &c, 1);

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	lookup[256] = {};

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if ((argv[1][i] == argv[2][j]) && (!lookuo[(int)argv[2][j]]))
				{
					lookup[(int)argv[2][j]] = 1;
					ft_putchar(argv[2][j]);
				}
				j++;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
