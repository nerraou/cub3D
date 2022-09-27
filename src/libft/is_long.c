/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:55:30 by nerraou           #+#    #+#             */
/*   Updated: 2022/09/27 11:55:31 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int check(unsigned long count, int sign)
{
	unsigned long max;

	if (sign == 1)
		max = (unsigned long)LONG_MAX;
	else
		max = -(unsigned long)LONG_MIN;
	if (count > max)
		return (0);
	return (1);
}

int is_long(const char *str)
{
	int i;
	int sign;
	unsigned long count;

	i = 0;
	sign = 1;
	count = (long)0;
	if (str[0] == '-')
		sign = (long)-1;
	i = (str[0] == '+' || str[0] == '-');
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		count = (long)(count * (long)10 + str[i] - '0');
		if (check(count, sign) == 0)
			return (0);
		i++;
	}
	return (1);
}
