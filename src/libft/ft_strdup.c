/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:51:58 by nerraou           #+#    #+#             */
/*   Updated: 2022/09/27 11:51:59 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char *ft_strdup(const char *s)
{
	int len;
	char *dst;

	len = ft_strlen(s);
	dst = (char *)ft_malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strcpy(dst, s);
	return (dst);
}
