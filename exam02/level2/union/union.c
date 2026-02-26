/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:57:35 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/26 14:26:42 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	seen[256] = {0};

	if (argc != 3)
		return (write(1, "\n", 1));
	i = 0;
	while (argv[1][i])
	{
		if (seen[(unsigned char)argv[1][i]] == 0)
		{
			write(1, &argv[1][i], 1);
			seen[(unsigned char)argv[1][i]] = 1;
		}
		i++;
	}
	j = 0;
	while (argv[2][j])
	{
		if (seen[(unsigned char)argv[2][j]] == 0)
		{
			write(1, &argv[2][j], 1);
			seen[(unsigned char)argv[2][j]] = 1;
		}
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
