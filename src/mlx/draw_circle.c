/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:25:38 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/10/15 17:35:24 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void draw_circle(t_data *data, int x0, int y0, int radius)
{
    int x;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err;

    x = radius - 1;
    err = dx - (radius << 1);
    while (x >= y)
    {
        ft_mlx_pixel_put(data, x0 + x, y0 + y);
        ft_mlx_pixel_put(data, x0 + y, y0 + x);
        ft_mlx_pixel_put(data, x0 - y, y0 + x);
        ft_mlx_pixel_put(data, x0 - x, y0 + y);
        ft_mlx_pixel_put(data, x0 - x, y0 - y);
        ft_mlx_pixel_put(data, x0 - y, y0 - x);
        ft_mlx_pixel_put(data, x0 + y, y0 - x);
        ft_mlx_pixel_put(data, x0 + x, y0 - y);

        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}
