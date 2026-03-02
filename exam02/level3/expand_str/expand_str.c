/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:28:31 by kcarrero          #+#    #+#             */
/*   Updated: 2026/03/02 11:38:33 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		first;
	char	*str;

	if (argc != 2)
		return (write(1, "\n", 1));
	i = 0;
	first = 1;
	str = argv[1];
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			write(1, &str[i], 1);
			first = 0;
			i++;
		}
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] && !first)
			write(1, "   ", 3);
	}
	write(1, "\n", 1);
	return (0);
}
