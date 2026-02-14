/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:01:13 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/14 14:43:11 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc != 4)
		return (write(1, "\n", 1));
	if (argv[2][1] != '\0' || argv[3][1] != '\0')
		return (write(1, "\n", 1));
	i = 0;
	while (argv[1][i])
	{
		c = argv[1][i];
		if (c == argv[2][0])
			c = argv[3][0];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
