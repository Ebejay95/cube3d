/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:25:38 by ajehle            #+#    #+#             */
/*   Updated: 2024/02/15 12:36:41 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_chars(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

static void	free_ptr(char **dptr)
{
	int	i;

	i = 0;
	while (dptr[i])
	{
		free(dptr[i]);
		dptr[i] = NULL;
		i++;
	}
	free(dptr);
	dptr = NULL;
}

static void	string_copy(char *dest, char *src, int chars, int start)
{
	int		count;

	count = 0;
	while (count < chars)
	{
		dest[count] = src[start + count];
		count++;
	}
	dest[count] = '\0';
}

static int	fill(char **dptr, char const *s, char c, int a_words)
{
	int	i;
	int	w;
	int	chars;

	i = 0;
	w = 0;
	while (w < a_words)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		chars = count_chars(&s[i], c);
		dptr[w] = (char *)malloc(sizeof(char) * (chars + 1));
		if (!dptr[w])
		{
			free_ptr(dptr);
			return (0);
		}
		string_copy(dptr[w], (char *)s, chars, i);
		i = i + chars;
		w++;
	}
	dptr[w] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		a_words;
	char	**dptr;

	i = 0;
	a_words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			a_words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	dptr = (char **)malloc(sizeof(char *) * (a_words + 1));
	if (!dptr || !s)
		return (NULL);
	if (!fill(dptr, s, c, a_words))
		return (NULL);
	return (dptr);
}
