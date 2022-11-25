/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:40:43 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 17:46:59 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		i = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	check_insert(char *num, int n, size_t len)
{
	int	i;

	i = len;
	if (n < 0)
	{
		while (i > 0)
		{
			num[i - 1] = '0' - n % 10;
			n /= 10;
			i--;
		}
		num[i] = '-';
	}
	else
	{
		while (i >= 0)
		{
			num[i - 1] = '0' + n % 10;
			n /= 10;
			i--;
		}
	}
	num[len] = '\0';
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*num;

	len = ft_numlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	check_insert(num, n, len);
	return (num);
}
