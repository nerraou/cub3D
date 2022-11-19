/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:47:05 by nerraou           #+#    #+#             */
/*   Updated: 2022/11/19 19:16:11 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int is_ray_facing_down(float angle)
{
	if (angle > 0.0f && angle < (float)M_PI)
		return 1;
	return -1;
}

int is_ray_facing_right(float angle)
{
	if (angle > 3.0f * (float)M_PI_2 || angle < (float)M_PI_2)
		return 1;
	return -1;
}

t_texture *define_texture(t_map *map, float angle, int horizontal)
{
	if (is_ray_facing_down(angle) == 1 && horizontal)
		return &(map->textures.so);
	if (is_ray_facing_down(angle) == -1 && horizontal)
		return &(map->textures.no);
	if (is_ray_facing_right(angle) == -1 && !horizontal)
		return &(map->textures.ea);
	else
		return &(map->textures.we);
}

void apply_wall_texture(t_data *data, t_texture *texture, float wall_strip_height, float ray_hit_point)
{
	float top_wall_hit;
	float botom_wall_hit;
	float step;
	float texture_pos;
	t_vector2 text_coor;

	top_wall_hit = ((data->height) / 2) - (wall_strip_height / 2);
	botom_wall_hit = ((data->height) / 2) + (wall_strip_height / 2);
	text_coor.x = ray_hit_point / data->scale;
	text_coor.x -= floor(text_coor.x);
	text_coor.x *= texture->width;
	step = ((float)texture->height / wall_strip_height);
	texture_pos = (topwallhit - data->height / 2.0f + wall_strip_height / 2.0f) * step;
}

float get_texture_x(float ray_hit_point, int scale, int texture_width)
{
	float texture_x;

	texture_x = ray_hit_point / scale;
	texture_x -= floor(texture_x);
	texture_x *= texture_width;

	return texture_x;
}

void render_3d_projection_wall(t_data *data, t_map *map, float angle_ray, int ray_num)
{
	float ray_distance;
	float distance_to_projection;
	float wall_strip_height;
	int horizontal;
	float ray_hit_point;

	distance_to_projection = ((data->width / 2) / tan(ray->fov_angle / 2));

	ray_distance = cast_ray(map, angle_ray, &horizontal, &ray_hit_point);
	ray_distance = ray_distance * cos(angle_ray - map->player.rotation_angle);
	wall_strip_height = map->scale / ray_distance * distance_to_projection;

	// apply_wall_texture(data, define_texture(map, angle_ray, horizontal), wall_strip_height, ray_hit_point);
}

void draw_walls(t_data *data, t_map *map, t_ray *ray)
{
	float move_angle;
	int i;

	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);
	i = 0;
	while (i < ray->num_rays)
	{
		move_angle = normalize_angle(move_angle);
		render_3d_projection_wall(data, map, move_angle, i);
	}
}

void draw_rays(t_data *data, t_ray *ray, t_map *map)
{
	float move_angle;
	float ray_distance;
	float distance;
	float wall_strip_height;
	int horizontal;
	int topwallhit;
	int botomwallhit;

	t_vector2 ray_hit_point;
	float step;
	int texture_x;

	horizontal = 0;
	move_angle = map->player.rotation_angle - (ray->fov_angle / 2);
	distance = ((data->width) / 2) / tan(ray->fov_angle / 2);
	t_texture *texture;
	int i = 0;
	while (i < ray->num_rays)
	{
		move_angle = normalize_angle(move_angle);
		ray_distance = cast_ray(data, map, move_angle, &horizontal, &ray_hit_point);
		ray_distance = ray_distance * cos(move_angle - map->player.rotation_angle);
		wall_strip_height = map->scale / ray_distance * distance;

		topwallhit = ((data->height) / 2) - (wall_strip_height / 2);
		botomwallhit = ((data->height) / 2) + (wall_strip_height / 2);

		texture = define_texture(map, move_angle, horizontal);
		if (horizontal)
			texture_x = ray_hit_point.x / map->scale;
		else
			texture_x = ray_hit_point.y / map->scale;
		texture_x -= floor(texture_x);
		texture_x *= texture->width;

		step = ((float)texture->height / wall_strip_height);
		float texture_pos = (topwallhit - data->height / 2.0f + wall_strip_height / 2.0f) * step;
		int texture_y;

		for (int y = topwallhit; y < botomwallhit; y++)
		{
			texture_y = (int)texture_pos & (texture->height - 1);
			texture_pos += step;
			int *texture_array = (int *)texture->addr;
			int color = texture_array[texture_y * texture->width + (int)texture_x];
			if (ray_distance > 5 * wall_strip_height)
				color = (color >> 1) & 8355711;
			fill(data, color);
			ft_mlx_pixel_put(data, i * ray->wall_width, y);
		}

		fill(data, map->ceiling_color);
		draw_rect(data, i * ray->wall_width, 0, ray->wall_width, topwallhit);
		fill(data, map->floor_color);
		draw_rect(data, i * ray->wall_width, botomwallhit, ray->wall_width, topwallhit);
		move_angle += ray->fov_angle / (data->width);
		i++;
	}
}
