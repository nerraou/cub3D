/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_widths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:33:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/19 10:11:25 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	set_map_widths(int **widths, char **map, int size)
{
	int	i;

	*widths = (int *)malloc(sizeof(int) * size);
	if (!*widths)
		return ;
	i = 0;
	while (map[i])
	{
		(*widths)[i] = ft_strlen(map[i]);
		i++;
	}
}
