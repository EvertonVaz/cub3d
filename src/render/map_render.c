/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:44:37 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/10 16:57:40 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int32_t	color_choice(char posicion)
{
	if (posicion == '0')
		return (ft_pixel(255, 255, 255, 255));
	if (posicion == '3')
		return (ft_pixel(255, 0, 0, 255));
	if (posicion == '2')
		return (ft_pixel(0, 0, 255, 255));
	return (ft_pixel(0, 0, 0, 255));
}

void	draw_square(t_cub *cub, int x, int y, int32_t color)
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

void	draw_map(void *param)
{
	int		x;
	int		y;
	int32_t	color;
	t_cub	*cub;

	cub = (t_cub *)param;
	y = -1;
	while (++y < cub->map_height)
	{
		x = -1;
		while (++x < cub->map_width)
		{
			color = color_choice(cub->map[y][x]);
			if (cub->player->y == y && cub->player->x == x)
				color = ft_pixel(255, 0, 0, 255);
			draw_square(cub, x * TILE_SIZE, y * TILE_SIZE, color);
		}
	}
	raycasting(cub);
}
