/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:25:00 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/21 17:43:33 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	distance(float start_x, float start_y, float end_x, float end_y)
{
	return (sqrtf(powf(end_x - start_x, 2.0f) + powf(end_y - start_y, 2.0f)));
}
