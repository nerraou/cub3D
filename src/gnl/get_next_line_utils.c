/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:38:27 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 17:40:48 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strclen(const char *s, int param)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != param)
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_line(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*str;

	i = 0;
	s1_len = ft_strclen(s1, '\0');
	s2_len = ft_strclen(s2, '\n');
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	while (s2[i] && s2[i] != '\n')
	{
		str[s1_len] = s2[i];
		s1_len++;
		i++;
	}
	str[s1_len] = '\0';
	return (str);
}
