/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:50:33 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/05 17:06:38 by kcarrero         ###   ########.fr       */
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
			if (c >= 'a' && c <= 'm')
				c = c + 13;
			else if (c >= 'n' && c <= 'z')
				c = c - 13;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			if (c >= 'A' && c <= 'M')
				c = c + 13;
			else if (c >= 'N' && c <= 'Z')
				c = c - 13;
		}
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
