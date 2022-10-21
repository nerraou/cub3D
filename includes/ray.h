/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:15:26 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/22 14:20:37 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

#include <math.h>
#include "ft_mlx.h"
#include "player.h"
typedef struct s_ray
{
	float fov_angle;
	int num_rays;
	int wall_width;
} t_ray;

#endif