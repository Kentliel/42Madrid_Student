/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:12:39 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/26 13:42:03 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	upper;

	if (argc != 2)
		return (0);
	i = 0;
	upper = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '_')
		{
			upper = 1;
			continue;
		}
		else if ((upper == 1) && (argv[1][i] >= 'a' && argv[1][i] <= 'z'))
		{
			write(1, (argv[1][i] - 32), 1);
			upper = 0;
			continue;
		}
		else
		{
			write(1, argv[1][i], 1);
		}
		i++;
	}
	return (0);
}
