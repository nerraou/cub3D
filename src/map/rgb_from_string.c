/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_from_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:18:10 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/10 22:07:21 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int rgb_from_string(const char *str)
{
    int r;
    int g;
    int b;
    int start_index;

    r = ft_atoi(str);

    start_index = ft_indexof(str, ',') + 1;
    g = ft_atoi(str + start_index);

    start_index = ft_indexof(str + start_index, ',') + 1;
    b = ft_atoi(str + start_index);
    return (r << 16 | g << 8 | b);
}
