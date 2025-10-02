/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:16:12 by seralves          #+#    #+#             */
/*   Updated: 2025/09/23 18:34:54 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t		count;
	int			inside_word;
	size_t		i;

	if (!s)
		return (0);
	count = 0;
	inside_word = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c) && (inside_word == 0))
		{
			inside_word = 1;
			count++;
		}
		else if (s[i] == c)
			inside_word = 0;
		i++;
	}
	return (count);
}

static char	*set_word(const char *s, ssize_t start, size_t end)
{
	char	*word;
	size_t	i;

	i = 0;
	word = ft_calloc((end - start + 1), sizeof(char));
	if (!word)
		return (NULL);
	while (start + (ssize_t)i < (ssize_t)end)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static void	*free_all(char **arr, size_t n_elements)
{
	size_t	i;

	i = 0;
	while (i < n_elements)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**splitter(char **split, char const *s, char c)
{
	size_t	i;
	size_t	i_split;
	ssize_t	start_word;

	start_word = -1;
	i = -1;
	i_split = 0;
	while (++i <= ft_strlen(s))
	{
		if ((s[i] != c) && (start_word < 0))
			start_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start_word >= 0)
		{
			split[i_split] = set_word(s, start_word, i);
			if (!split[i_split])
				return (free_all(split, i_split));
			start_word = -1;
			i_split++;
		}
	}
	split[i_split] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = ft_calloc((count_words(s, c) + 1), sizeof (char *));
	if (!split)
		return (NULL);
	return (splitter(split, s, c));
}
