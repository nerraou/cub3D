/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_down_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:30:43 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/17 10:31:26 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int mlx_key_down_hook(void *win_ptr, int (*handler)(), void *param)
{
	return mlx_hook(win_ptr, 02, 1L << 0, handler, param);
}
