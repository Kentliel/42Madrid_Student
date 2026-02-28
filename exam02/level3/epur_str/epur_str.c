/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:43:18 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/28 16:29:19 by kcarrero         ###   ########.fr       */
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
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
			first = 0;
		}
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] && !first)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}
