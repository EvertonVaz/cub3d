/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycating_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:07:50 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/14 07:34:43 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	calculate_texture_coordinates(t_cub *cub)
{
	t_ray	*ray;

	ray = cub->ray;
	if (ray->side == 0)
		ray->wall_x = cub->player->y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = cub->player->x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEX_SIZE);
	if (ray->side == 0 && ray->dir_x > 0)
		ray->tex_x = TEX_SIZE - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		ray->tex_x = TEX_SIZE - ray->tex_x - 1;
}

int32_t	texture_to_color(mlx_texture_t *tex, int x, int y)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;
	int		index;

	index = (y * tex->width + x) * 4;
	r = tex->pixels[index];
	g = tex->pixels[index + 1];
	b = tex->pixels[index + 2];
	a = tex->pixels[index + 3];
	return (ft_pixel(r, g, b, a));
}

int32_t	select_color(t_cub *cub, int tex_x, int y)
{
	int	tex_y;

	tex_y = (((y * 256 - HEIGHT * 128 + cub->ray->line_height * 128) * TEX_SIZE)
			/ cub->ray->line_height) / 256;
	if (cub->ray->side == 0 && cub->ray->dir_x > 0)
		return (texture_to_color(cub->texture->e_tex, tex_x, tex_y));
	if (cub->ray->side == 0 && cub->ray->dir_x < 0)
		return (texture_to_color(cub->texture->w_tex, tex_x, tex_y));
	if (cub->ray->side == 1 && cub->ray->dir_y > 0)
		return (texture_to_color(cub->texture->s_tex, tex_x, tex_y));
	if (cub->ray->side == 1 && cub->ray->dir_y < 0)
		return (texture_to_color(cub->texture->n_tex, tex_x, tex_y));
	return (0);
}
