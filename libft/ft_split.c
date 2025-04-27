/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:50:52 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/27 14:18:31 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordscounter(char const *s, char c)
{
	size_t	i;
	size_t	count;

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

static void	ft_freesplit(char **list, size_t words_allocat)
{
	size_t	i;

	i = 0;
	while (i < words_allocat)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

static char	*ft_extractnextword(char const **s_ptr, char delimiter)
{
	char const	*word_start;
	char const	*s_current;
	size_t		word_len;
	char		*word;

	s_current = *s_ptr;
	while (*s_current != '\0' && *s_current == delimiter)
		s_current++;
	word_start = s_current;
	while (*s_current != '\0' && *s_current != delimiter)
		s_current++;
	word_len = s_current - word_start;
	word = ft_substr(word_start, 0, word_len);
	*s_ptr = s_current;
	return (word);
}

static int	ft_fillwords(char **list, char const *s, char del, size_t max_words)
{
	size_t		word_index;
	char const	*s_current;
	char		*current_word;

	s_current = s;
	word_index = 0;
	while (word_index < max_words)
	{
		current_word = ft_extractnextword(&s_current, del);
		if (!current_word)
		{
			ft_freesplit(list, word_index);
			return (0);
		}
		list[word_index] = current_word;
		word_index++;
	}
	list[word_index] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**list;
	size_t		max_words;

	if (!s)
		return (NULL);
	max_words = ft_wordscounter(s, c);
	list = (char **)malloc(sizeof(char *) * (max_words + 1));
	if (!list)
		return (NULL);
	if (!ft_fillwords(list, s, c, max_words))
		return (NULL);
	return (list);
}
