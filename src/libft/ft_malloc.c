/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:47:29 by nerraou           #+#    #+#             */
/*   Updated: 2022/09/27 11:47:30 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_malloc(size_t size)
{
	void *arr;

	arr = malloc(size);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, size);
	return (arr);
}
