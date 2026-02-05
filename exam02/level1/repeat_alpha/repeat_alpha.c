/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:14:06 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/05 16:16:12 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		n;
	char	c;

	if (argc != 2)
		return (write(1, "\n", 1));
	i = 0;
	while (argv[1][i])
	{
		c = argv[1][i];
		if (c >= 'a' && c <= 'z')
			n = c - 'a' + 1;
		else if (c >= 'A' && c <= 'Z')
			n = c - 'A' + 1;
		else
			n = 1;
		while (n--)
			write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}
