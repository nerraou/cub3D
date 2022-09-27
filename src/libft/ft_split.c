/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:51:26 by nerraou           #+#    #+#             */
/*   Updated: 2022/09/27 11:51:31 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_strclen(const char *str, char c)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static size_t word_count(char const *s, char c)
{
	int index;
	size_t word;

	word = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index])
			word++;
		while (s[index] && s[index] != c)
			index++;
	}
	return (word);
}

static char **ft_free(char **str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char **ft_split(char const *s, char c)
{
	char **str;
	size_t i;
	size_t words;
	size_t start;
	size_t length;

	words = word_count(s, c);
	i = 0;
	start = 0;
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	while (i < words)
	{
		while (s[start] == c && s[start])
			start++;
		length = ft_strclen(s + start, c);
		str[i] = ft_substr(s, start, length);
		if (!str[i])
			return (ft_free(str, i));
		start += length;
		i++;
	}
	str[i] = NULL;
	return (str);
}