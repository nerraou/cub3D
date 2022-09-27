/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:49:23 by nerraou           #+#    #+#             */
/*   Updated: 2022/09/27 11:49:35 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d_str;
	const unsigned char *s_str;
	size_t i;

	d_str = dest;
	s_str = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		d_str[i] = s_str[i];
		i++;
	}
	return (dest);
}