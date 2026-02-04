/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:49:32 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/04 13:56:41 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	i = 0;
	while (ft_isspace(argv[1][i]))
		i++;
	if (argv[1][i] == '\0')
	{
		write(1, "\n", 1);
		return (1);
	}
	while (!ft_isspace(argv[1][i]) && argv[1][i] != '\0')
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
