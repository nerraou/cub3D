/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_floor_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:27:38 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/10 23:14:38 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int set_floor_color(const char *line, t_map *map)
{
    map->floor_color = rgb_from_string(line + 1);
    return (0);
}
