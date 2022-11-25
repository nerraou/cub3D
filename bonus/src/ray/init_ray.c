/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:12:26 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 16:37:24 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	init_ray(t_ray *ray, int window_width)
{
	ray->fov_angle = 60.0f * (M_PI / 180.0f);
	ray->wall_width = 1;
	ray->num_rays = window_width / ray->wall_width;
}
