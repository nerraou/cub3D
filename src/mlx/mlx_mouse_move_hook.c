/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_move_hook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:29 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/23 09:29:05 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int	mlx_mouse_move_hook(void *win_ptr, int (*handler)(), void *param)
{
	return (mlx_hook(win_ptr, 6, 1L << 6, handler, param));
}
