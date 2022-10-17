/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_up_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:31:59 by nerraou           #+#    #+#             */
/*   Updated: 2022/10/17 10:32:18 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int mlx_key_up_hook(void *win_ptr, int (*handler)(), void *param)
{
	return mlx_hook(win_ptr, 03, 1L << 1, handler, param);
}