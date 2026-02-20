/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:54:04 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/20 14:53:11 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc != 4)
		return (write(1, "\n", 1));
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	if (argv[2][0] == '+' )
		return (printf("%d\n", a + b));
	else if (argv[2][0] == '-')
		return (printf("%d\n", a - b));
	else if (argv[2][0] == '*')
		return (printf("%d\n", a * b));
	else if (argv[2][0] == '/')
		return (printf("%d\n", a / b));
	else if (argv[2][0] == '%')
		return (printf("%d\n", a % b));
	return (0);
}
