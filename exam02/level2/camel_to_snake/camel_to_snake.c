/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:27:24 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/14 15:46:43 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc != 2)
		return (write(1, "\n", 1));
	i = 0;
	while (argv[1][i])
	{
		c = argv[1][i];
		if (c >= 'A' && c <= 'Z')
		{
			write(1, "_", 1);
			c = c + 32;
			write(1, &c, 1);
		}
		else
			write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
