/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:38:05 by kcarrero          #+#    #+#             */
/*   Updated: 2026/03/04 13:33:06 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static void	put_word(char *s, int start, int end)
{
	while (start < end)
		write(1, &s[start++], 1);
}

int	main(int argc, char **argv)
{
	char	*s;
	int		i;
	int		first_start;
	int		first_end;
	int		start;
	int		printed;

	if (argc < 2)
		return (write(1, "\n", 1));

	s = argv[1];
	i = 0;
	while (s[i] && is_space(s[i]))
		i++;
	first_start = i;
	while (s[i] && !is_space(s[i]))
		i++;
	first_end = i;

	printed = 0;
	while (s[i])
	{
		while (s[i] && is_space(s[i]))
			i++;
		if (!s[i])
			break;
		if (printed)
			write(1, " ", 1);
		start = i;
		while (s[i] && !is_space(s[i]))
			i++;
		put_word(s, start, i);
		printed = 1;
	}
	if (first_end > first_start)
	{
		if (printed)
			write(1, " ", 1);
		put_word(s, first_start, first_end);
	}
	write(1, "\n", 1);
	return (0);
}
