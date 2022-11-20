/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahlaou <ybahlaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:28:19 by ybahlaou          #+#    #+#             */
/*   Updated: 2022/11/20 13:12:51 by ybahlaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char	*skip_empty_lines(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		if (*line != '\0')
			return (line);
		free(line);
	}
	return (NULL);
}

static int	max_width(int *widths, int len)
{
	int	i;
	int	max_value;

	max_value = widths[0];
	i = 1;
	while (i < len)
	{
		if (widths[i] > max_value)
			max_value = widths[i];
		i++;
	}
	return (max_value);
}

static int	has_bad_char(const char *str)
{
	int	i;

	if (str[0] == '\0')
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_indexof(" 10NEWS", str[i]) == -1)
			return (1);
		i++;
	}
	return (0);
}

static int	read_map(int fd, t_list **list)
{
	char	*line;
	int		has_bad_chars;

	line = skip_empty_lines(fd);
	if (!line)
		return (perror_and_return("missing map", 1));
	*list = list_new();
	if (!list)
	{
		free(line);
		return (perror_and_return("cannot allocate memory", 1));
	}
	has_bad_chars = 0;
	while (line && !has_bad_chars)
	{
		add_back(*list, (void *)line);
		has_bad_chars = has_bad_char(line);
		if (!has_bad_chars)
			line = get_next_line(fd);
	}
	if (has_bad_chars)
		return (perror_and_return("there is bad characters in the map", 1));
	return (0);
}

int	map_parse_map(int fd, t_map *map)
{
	t_list	*list;
	int		read_map_error;

	list = NULL;
	read_map_error = read_map(fd, &list);
	if (read_map_error == 0)
	{
		map->map_array = list_to_array(list);
		set_map_widths(&map->widths, map->map_array, list->size);
		map->height = list->size;
		map->width = max_width(map->widths, list->size);
	}
	if (list)
		list_del(&list, list_del_noop);
	if (read_map_error == 0 && map->height <= 2)
		return (perror_and_return("map should contain at least 3 rows", 1));
	return (read_map_error);
}
