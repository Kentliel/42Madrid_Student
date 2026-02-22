/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:00:28 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/23 00:35:13 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	start;
	int	end;

	if (argc != 2)
		return (write(1, "\n", 1));
	i = 0;
	while (argv[1][i])
		i++;
	i--;
	while ((argv[1][i] >= 9 && argv[1][i] <= 13) || (argv[1][i] == ' '))
		i--;
	end = i;
	while (i >= 0 && !((argv[1][i] >= 9 && argv[1][i] <= 13) || (argv[1][i] == ' ')))
		i--;
	start = i + 1;
	while (start <= end)
	{
		write(1, &argv[1][start], 1);
		start++;
	}
	write(1, "\n", 1);
	return (0);
}
