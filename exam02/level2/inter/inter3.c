/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:47:05 by kcarrero          #+#    #+#             */
/*   Updated: 2026/02/22 23:58:54 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_putchar(char c)
	return (write(1, &c, 1));

static int already_seen(char *s, char c, int pos)
{
	int k;

	k = 0;
	while (k < pos)
	{
		if (s[k] == c)
			return (1);
		k++;
	}
	return (0);
}

static int	in_second(char *s2, char c)
{
	int	j;

	j = 0;
	while (s2[j])
	{
		if (s2[j] == c)
			return (1);
		j++;
	}
	return (0);
}

static void	inter(char *s1, char *s2)
{
	int	i;

	i = 0;

	while (s1[i])
	{
		if ((!already_see(s1, s1[i], i)) && (in_second(s2, s1,[i])))
			ft_putchar(s1[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	inter(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
