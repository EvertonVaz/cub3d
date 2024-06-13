/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycating_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:07:50 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/13 11:33:50 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	calculate_texture_coordinates(t_cub *cub)
{
	t_ray	*ray;

	ray = cub->ray;
	if (ray->side == 0)
		ray->wallX = cub->player->y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wallX = cub->player->x + ray->perp_wall_dist * ray->dir_x;
	ray->wallX -= floor(ray->wallX);
	ray->texX = (int)(ray->wallX * (double)TEX_SIZE);
	if (ray->side == 0 && ray->dir_x > 0)
		ray->texX = TEX_SIZE - ray->texX - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		ray->texX = TEX_SIZE - ray->texX - 1;
}

int32_t	texture_to_color(mlx_texture_t *tex, int x, int y)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;
	int index;

	index = (y * tex->width + x) * 4;
    r = tex->pixels[index];
    g = tex->pixels[index + 1];
    b = tex->pixels[index + 2];
    a = tex->pixels[index + 3];
	return (ft_pixel(r, g, b, a));
}

int32_t	select_color(t_cub *cub, int texX, int y)
{
	int	texY;

	texY = (((y * 256 - HEIGHT * 128 + cub->ray->line_height * 128) * TEX_SIZE)
		/ cub->ray->line_height) / 256;
	if (cub->ray->side == 0 && cub->ray->dir_x > 0)
		return (texture_to_color(cub->texture->e_tex, texX, texY));
	if (cub->ray->side == 0 && cub->ray->dir_x < 0)
		return (texture_to_color(cub->texture->w_tex, texX, texY));
	if (cub->ray->side == 1 && cub->ray->dir_y > 0)
		return (texture_to_color(cub->texture->s_tex, texX, texY));
	if (cub->ray->side == 1 && cub->ray->dir_y < 0)
		return (texture_to_color(cub->texture->n_tex, texX, texY));
	return (0);
}
