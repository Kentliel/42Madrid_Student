/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:50:52 by kcarrero          #+#    #+#             */
/*   Updated: 2025/04/24 20:58:57 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//

static int	ft_wordscounter(char const *s, char c)
{
	size_t	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c)
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

char	**ft_split(char const *s, char c)
{
	char **split;
	size_t	max_words;
	size_t	start;
	size_t	end;
	//la cadena es valida ¿¿ existe ¿¿
	if (!s)
		return (NULL);
	split = NULL;
	max_words = ft_wordscounter(s, c);
	split = malloc(sizeof(char *) * max_words + 1);
	//necesitamos mientras que max_words > 0
	while ()
		//while averiguar la dimension de la palabra start = 0, end == n veces antes de encontrarse con el caracter c.
		//ft_allocate_word(char **split,index_word, len)intentas alocar y guardar cada palabra dentro de la lista
		//no puedo alocar una palabra > libero lo que estaba intentando alocar + la lista entera

	split[max_words] = NULL;
	return (split);
}
