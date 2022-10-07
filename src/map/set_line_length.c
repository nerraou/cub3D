/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_line_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:33:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/07 14:25:27 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void set_line_length(int **length, char **map, int size)
{
	*length = (int *)malloc(sizeof(int) * size);
	if (!*length)
		return;
	int i;

	i = 0;
	while (map[i])
	{
		(*length)[i] = ft_strlen(map[i]);
		i++;
	}
}
