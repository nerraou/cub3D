/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:55:06 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/23 23:14:24 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	should_parse_colors(const char *line)
{
	return line[0] == 'F' || line[0] == 'C';
}

static int	should_parse_textures(const char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (1);
	if (ft_strncmp(line, "SO", 2) == 0)
		return (1);
	if (ft_strncmp(line, "WE", 2) == 0)
		return (1);
	if (ft_strncmp(line, "EA", 2) == 0)
		return (1);
	return (0);
}

static int	parse_colors_from_line(char *line, t_map *map)
{
	int	has_error;

	has_error = set_colors(line, map);
	if (has_error)
		return (perror_and_return("bad color format, use F|C r,g,b"
			", or duplicated color", 2));
	return (0);
}

static int	parse_texture_from_line(char *line, t_map *map)
{
	int	has_error;

	has_error = set_textures(line, map);
	if (has_error)
		return (perror_and_return("bad texture format, use NO|SO|WE|EA path"
			", or duplicated texture", 2));
	return (0);
}

int map_parse_header(int fd, t_map *map)
{
	char	*line;
	int		has_error;

	line = NULL;
	has_error = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (should_parse_colors(line))
			has_error = parse_colors_from_line(line, map);
		else if (should_parse_textures(line))
			has_error = parse_texture_from_line(line, map);
		else if (line[0] != '\0')
			has_error = 1;
		free(line);
		if (has_error || map_has_header(map))
			break;
	}
	if (has_error != 2 && !map_has_header(map))
		return (perror_and_return("missing or bad header information", 1));
	if (has_error)
		return (1);
	return (0);
}
