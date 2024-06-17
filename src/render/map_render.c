/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:44:37 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/17 12:53:44 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	paint_background(t_cub *cub)
{
	int	half;
	int	x;
	int	y;

	half = HEIGHT / 2;
	y = -1;
	while (++y <= half)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(cub->mlx->img, x, y, cub->ceiling_color);
	}
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(cub->mlx->img, x, y, cub->floor_color);
	}
}

void	render(void *param)
{
	t_cub	*cub;
	int		x;
	int		y;
	int		width;

	cub = (t_cub *)param;
	paint_background(cub);
	raycasting(cub);
	y = -1;
	while (++y < cub->map_height)
	{
		x = -1;
		width = ft_strlen(cub->map[y]);
		while (++x < width)
		{
			if (cub->map && cub->map[y][x] && cub->map[y][x] == ' ')
				continue ;
			mini_map(cub, x * TILE_SIZE, y * TILE_SIZE, mini_color(cub, x, y));
		}
	}
}
