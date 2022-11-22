/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:42:35 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/22 10:44:31 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	open_map(const char *path)
{
	if (!ft_strendswith(path, ".cub"))
		return (-2);
	return (open(path, O_RDONLY));
}
