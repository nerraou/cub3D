/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:25:38 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/10/10 22:02:50 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_rect(t_data *data, int x, int y, int width, int height)
{
    int dx;

    height += y;
    width += x;
    while (y <= height)
    {
        dx = x;
        while (dx < width)
        {
            ft_mlx_pixel_put(data, dx, y);
            dx++;
        }
        y++;
    }
}
