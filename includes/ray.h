/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:15:26 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/19 11:01:30 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include <math.h>
#include "player.h"
typedef struct s_ray
{
	float fov_angle;
	int num_rays;
	int wall_width;
} t_ray;

void init_ray(t_ray *ray, int window_width);

#endif
