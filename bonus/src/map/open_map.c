/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:42:35 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/23 22:49:59 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	open_map(const char *path)
{
	int	fd;

	if (!ft_strendswith(path, ".cub"))
		return (perror_and_return("bad file extension, use .cub", -1));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror_and_return(strerror(errno), -1));
	return (fd);
}
