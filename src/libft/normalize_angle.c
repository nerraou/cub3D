/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:22:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/01 16:23:06 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

float normalize_angle(float angle)
{
	angle = fmodf(angle, (2.0f * (float)M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return angle;
}
