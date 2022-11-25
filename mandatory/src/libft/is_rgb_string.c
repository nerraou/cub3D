/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:28:34 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/19 18:46:56 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	commas_count(const char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count += *str == ',';
		str++;
	}
	return (count);
}

static int	is_in_range(const char *str, int len)
{
	int	value;

	if (len == 0 || len > 3)
		return (0);
	value = ft_atoi(str);
	if (value < 0 || value > 255)
		return (0);
	return (1);
}

int	is_string_rgb(const char *str)
{
	int	comma_index;

	if (commas_count(str) != 2)
		return (0);
	while (*str != '\0')
	{
		comma_index = ft_indexof(str, ',');
		if (comma_index == -1)
			comma_index = ft_strlen(str);
		if (!is_in_range(str, comma_index))
			return (0);
		str += comma_index;
		if (*str)
			str++;
	}
	return (1);
}
