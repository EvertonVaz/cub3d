/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:19:42 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/10 17:59:09 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	player_move(t_cub *cub)
{
	mlx_t	*mlx;
	double	x;
	double	y;

	mlx = cub->mlx->mlx;
	x = cub->player->x;
	y = cub->player->y;
	if (mlx_is_key_down(mlx, MLX_KEY_W) && !hit(cub))
	{
		cub->player->x += cub->player->dir_x;
		cub->player->y += cub->player->dir_y;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		cub->player->x -= cub->player->dir_x;
		cub->player->y -= cub->player->dir_y;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		cub->player->y += cub->player->dir_x;
		cub->player->x -= cub->player->dir_y;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		cub->player->y -= cub->player->dir_x;
		cub->player->x += cub->player->dir_y;
	}
	return (y != cub->player->y || x != cub->player->x);
}

void	player_walk(mlx_key_data_t key, void *param)
{
	t_cub *cub = (t_cub *)param;

	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(cub->mlx->mlx);
	if (player_move(cub))
	{
		draw_map(cub);
		printf("Player position: x = %d, y = %d\n", (int)cub->player->x, (int)cub->player->y);
	}
}
