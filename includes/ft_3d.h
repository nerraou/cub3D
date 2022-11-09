/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:35:01 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/08 15:01:29 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_3D_H
#define FT_3D_H
#include "ft_mlx.h"

void render_3d_projection_wall(t_data *data, t_map *map, t_ray *ray, float distance);

#endif
