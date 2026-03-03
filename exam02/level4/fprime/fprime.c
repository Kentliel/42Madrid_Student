/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:32:19 by kcarrero          #+#    #+#             */
/*   Updated: 2026/03/03 15:38:12 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	number;
	int	i;
	int	first;

	if (argc != 2)
		return (printf("\n"));
	number = atoi(argv[1]);
	if (number == 1)
	{
		printf("1\n");
		return (0);
	}
	i = 2;
	first = 1;
	while (i <= number)
	{
		if (number % i == 0)
		{
			if (!first)
				printf("*");
			printf("%d", i);
			n /= i;
			first = 0;
		}
		else
			i++;
	}
	printf("\n");
	return (0);
}
