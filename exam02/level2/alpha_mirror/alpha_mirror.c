/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:12:24 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/14 15:25:31 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		if (c >= 'a' && c <= 'z')
			c = 'z' - (c - 'a');
		else if (c >= 'A' && c <= 'Z')
			c = 'Z' - (c - 'A');
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
