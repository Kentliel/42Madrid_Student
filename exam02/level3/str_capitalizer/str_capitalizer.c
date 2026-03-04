/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:33:48 by kcarrero          #+#    #+#             */
/*   Updated: 2026/03/04 23:40:47 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

char to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	is_letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	c;

	if (argc < 2)
		return (write(1, "\n", 1), 0);
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			c = to_lower(argv[i][j]);
			if (is_letter(c) && (j == 0 || argv[i][j - 1] == ' ' || argv[i][j - 1] == '\t'))
				c = to_upper(c);
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
