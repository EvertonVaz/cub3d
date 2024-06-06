/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:19:42 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/06 15:25:50 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	up_down(t_cub *cub)
{
	mlx_t	*mlx;
	int		x;
	int		y;

	mlx = cub->screen->mlx;
	x = cub->player->x;
	y = cub->player->y;
	if (mlx_is_key_down(mlx, MLX_KEY_W) && cub->map[y - 1][x] != '1')
		cub->player->y--;
	if (mlx_is_key_down(mlx, MLX_KEY_S) && cub->map[y + 1][x] != '1')
		cub->player->y++;
}

void	left_right(t_cub *cub)
{
	mlx_t	*mlx;
	int		x;
	int		y;

	mlx = cub->screen->mlx;
	x = cub->player->x;
	y = cub->player->y;
	if (mlx_is_key_down(mlx, MLX_KEY_A) && cub->map[y][x - 1] != '1')
		cub->player->x--;
	if (mlx_is_key_down(mlx, MLX_KEY_D) && cub->map[y][x + 1] != '1')
		cub->player->x++;
}

void	player_walk(void *param)
{
	t_cub *cub = (t_cub *)param;

	if (mlx_is_key_down(cub->screen->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->screen->mlx);
	up_down(cub);
	left_right(cub);
}