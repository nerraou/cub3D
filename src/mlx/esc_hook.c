/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:05:14 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/15 13:26:55 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int esc_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	return (0);
}
