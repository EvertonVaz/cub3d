/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:51:24 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/10 17:03:50 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_ray(t_player *player, t_ray *ray)
{
	ray->camera_x = 2 * player->x / (double)WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->hit = 0;
}

void	side_dist(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

int	hit(t_cub *cub, t_ray * ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
	if (cub->map[ray->map_y][ray->map_x] == '1')
		ray->hit = 1;
	return (ray->hit);
}

void	draw_line(t_cub *cub, int x)
{
	t_ray	*ray;
	int32_t	color;

	ray = cub->ray;
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	while (ray->draw_start < ray->draw_end)
	{
		color = ft_pixel(0, 0, 0, 255);
		if (cub->map[ray->map_y][ray->map_x] == '3')
			color = ft_pixel(255, 255, 255, 255);
		if (cub->map[ray->map_y][ray->map_x] == '1')
			color = ft_pixel(255, 0, 0, 255);
		if (cub->map[ray->map_y][ray->map_x] == '2')
			color = ft_pixel(0, 0, 255, 255);
		if(ray->side == 1)
			color = color / 2;
		mlx_put_pixel(cub->mlx->img, x, ray->draw_start, color);
		ray->draw_start++;
	}
}

void	raycasting(t_cub *cub)
{
	t_player	*player;
	t_ray		*ray;
	int			x;

	player = cub->player;
	ray = cub->ray;
	x = -1;
	while (++x < WIDTH)
	{
		init_ray(player, ray);
		side_dist(ray, player);
		while (hit(cub, ray) == 0)
			;
		if (ray->side == 0)
			ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
		else
			ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
		draw_line(cub, x);
	}
}
