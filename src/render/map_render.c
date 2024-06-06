/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:44:37 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/06 15:11:49 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_square(t_cub *cub, int x, int y, int32_t color)
{
	int	x_square;
	int	y_square;

	y_square = y * HEIGHT / cub->map_height;
	while (y_square < HEIGHT)
	{
		x_square = x * WIDTH / cub->map_width;
		while (x_square < WIDTH)
		{
			mlx_put_pixel(cub->screen->img, x_square, y_square, color);
			x_square++;
		}
		y_square++;
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
			color = ft_pixel(0, 0, 0, 255);
			if (cub->map[y][x] == '0')
				color = ft_pixel(255, 255, 255, 255);
			if (cub->player->y == y && cub->player->x == x)
				color = ft_pixel(255, 0, 0, 255);
			draw_square(cub, x, y, color);
		}
	}
}
