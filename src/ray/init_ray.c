/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:12:26 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/24 18:43:22 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void init_ray(t_ray *ray)
{
	ray->fov_angle = 60.0f * (M_PI / 180.0f);
	ray->wall_width = 1;
	ray->num_rays = (32 * 20) / ray->wall_width;
}
