/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:28:49 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/23 19:30:09 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

typedef struct s_vector2
{
	float	x;
	float	y;
}			t_vector2;

void	vector2_set(t_vector2 *vector, float x, float y);
void	vector2_set_x(t_vector2 *vector, float x);
void	vector2_set_y(t_vector2 *vector, float y);

#endif
