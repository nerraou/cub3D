/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:53:48 by nerraou           #+#    #+#             */
/*   Updated: 2022/09/27 11:53:57 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char *str1;
	unsigned const char *str2;
	size_t i;
	int diff;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	diff = -1;
	while (i < n && str1[i] && str2[i])
	{
		diff = str1[i] - str2[i];
		if (diff != 0)
			break;
		i++;
	}
	return (diff);
}
