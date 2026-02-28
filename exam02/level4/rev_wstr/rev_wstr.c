/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:27:18 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/28 14:34:31 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	if (argc != 2)
		return(write(1, "\n", 1));
	i = 0;
	str = argv[1];
	while (str[i])
		i++;
	while (i > 0)
	{
		i--;
		if (str[i] == ' ' || str[i] == '\t')
			continue;
		end = i;
		while (i > 0 && str[i - 1] != ' ' && str[i - 1] != '\t')
			i--;
		start = i;
		write(1, &str[start], end - start + 1);
		if (i > 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}
