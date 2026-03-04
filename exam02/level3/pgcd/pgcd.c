/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:15:49 by kcarrero          #+#    #+#             */
/*   Updated: 2026/03/04 23:18:19 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	tmp;

	if (argc != 3)
		return (printf("\n"), 0);
	a = atoi(argv[1]);
	b = atoi(argv[2]);

	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	printf("%d\n", a);
	return (0);
}
