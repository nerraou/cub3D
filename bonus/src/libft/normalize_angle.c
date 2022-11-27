/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:22:50 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/27 13:45:58 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	normalize_angle(float angle)
{
	angle = fmodf(angle, (2.0f * (float)M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}
