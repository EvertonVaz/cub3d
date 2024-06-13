/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:44:37 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/13 14:21:33 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int32_t	minimap_color(t_cub *cub, int x, int y)
{
	if ((int)cub->player->x == x && (int)cub->player->y == y)
		return (ft_pixel(255, 0, 0, 255));
	if (cub->map && cub->map[y][x] && cub->map[y][x] == '0')
		return (ft_pixel(255, 255, 255, 255));
	return (ft_pixel(0, 0, 0, 255));
}

void	mini_map(t_cub *cub, int x, int y, int32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx_put_pixel(cub->mlx->img, (x + j), (y + i), color);
			j++;
		}
		i++;
	}
}

void	paint_background(t_cub *cub)
{
	int	half = HEIGHT / 2;
	int	x;
	int	y;

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
				continue;
			mini_map(cub, x * TILE_SIZE, y * TILE_SIZE, minimap_color(cub, x, y));
		}
	}
}
