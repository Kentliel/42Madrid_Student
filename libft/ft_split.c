/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:50:52 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/25 20:05:43 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordscounter(char const *s, char c)
{
	size_t	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_alloc_word(char **spl, size_t index_word, size_t len)
{
	spl[index_word] = malloc(sizeof(char) * len + 1);
	if (!spl[index_word])
	{
		while (index_word > 0)
		{
			index_word--;
			free(spl[index_word]);
		}
		free(spl);
		return (NULL);
	}
	return (spl);
}

static char	*ft_createsub(const char *s, unsigned int index, size_t len)
{
	char *newstr;

	newstr = ft_substr(s, index, len);
	return (newstr);
}

char	**ft_split(char const *s, char c)
{
	char 			**list;
	size_t			max_words;
	size_t			start;
	size_t			end;
	unsigned int	i;
	
	if (!s)
		return (NULL);
	max_words = ft_wordscounter(s, c);
	list = malloc(sizeof(char *) * max_words + 1);
	i = 0;
	end = 0;
	start = 0;
	while (max_words > 0)
	{
		while (s[end] != c)
			end++;
		if (!ft_alloc_word(list, i, (end - start)))
			return (NULL);
		list[i] = ft_createsub(s, start, (end - start));
		start = end + 1;
		if (s[end + 1] != '\0')
			end++;
		i++;
		max_words--;
	}
	list[i] = NULL;
	return (list);
}
