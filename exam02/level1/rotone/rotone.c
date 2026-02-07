/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:47:47 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/07 14:58:41 by kcarrero         ###   ########.fr       */
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
		{
			if (c == 'z')
				c = 'a';
			else
				c = c + 1;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			if (c == 'Z')
				c = 'A';
			else
				c = c + 1;
		}
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
