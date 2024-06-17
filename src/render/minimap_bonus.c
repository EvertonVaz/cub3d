/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:53:53 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/17 12:53:59 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int32_t	mini_color(t_cub *cub, int x, int y)
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