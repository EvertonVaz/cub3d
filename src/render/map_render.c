/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:44:37 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/11 18:55:14 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int32_t	color_choice(t_cub cub, int x, int y)
{
	char	posicion;

	posicion = cub.map[y][x];
	if (cub.player->x == x && cub.player->y == y)
		return (ft_pixel(255, 0, 0, 255));
	if (posicion == '0')
		return (ft_pixel(255, 255, 255, 255));
	if (posicion == '3')
		return (ft_pixel(255, 0, 0, 255));
	if (posicion == '2')
		return (ft_pixel(0, 0, 255, 255));
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

void	draw_map(void *param)
{
	t_cub	*cub;
	int		x;
	int		y;

	cub = (t_cub *)param;
	y = -1;
	paint_background(cub);
	raycasting(cub);
	while (++y < cub->map_height)
	{
		x = -1;
		while (++x < cub->map_width)
			mini_map(cub, x * TILE_SIZE, y * TILE_SIZE, color_choice(*cub, x, y));
	}
}
