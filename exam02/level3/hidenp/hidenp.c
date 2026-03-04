/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 22:51:38 by kcarrero          #+#    #+#             */
/*   Updated: 2026/03/04 23:09:41 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	if (argc != 3)
		return (write(1, "\n", 1), 0);
	i = 0;
	j = 0;
	str1 = argv[1];
	str2 = argv[2];
	while (str1[i] && str2[j])
	{
		if (str1[i] == str2[j])
		{
			i++;
		}
		j++;
	}
	if (str1[i] == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
