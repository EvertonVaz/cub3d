/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:19:42 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/10 21:58:04 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	up_down(t_cub *cub)
{
	double	x;
	double	y;
	int		dir_x;
	int		dir_y;

	x = cub->player->x;
	y = cub->player->y;
	dir_x = cub->player->dir_x;
	dir_y = cub->player->dir_y;
	if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_W))
	{
		if (cub->map[(int)(y + dir_y * SPEED)][(int)cub->player->x] == '0')
			cub->player->x += cub->player->dir_x * SPEED;
		if (cub->map[(int)cub->player->y][(int)(x + dir_x * SPEED)] == '0')
			cub->player->y += cub->player->dir_y * SPEED;
	}
	if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_S))
	{
		if (cub->map[(int)(y - dir_y * SPEED)][(int)cub->player->x] == '0')
			cub->player->x -= cub->player->dir_x * SPEED;
		if (cub->map[(int)cub->player->y][(int)(x - dir_x * SPEED)] == '0')
			cub->player->y -= cub->player->dir_y * SPEED;
	}
	return (y != cub->player->y || x != cub->player->x);
}

int	left_right(t_cub *cub)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = cub->player->dir_x;
	old_plane_x = cub->player->plane_x;
	if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_A))
	{
		cub->player->dir_x = cub->player->dir_x * cos(SPEED) - cub->player->dir_y * sin(SPEED);
		cub->player->dir_y = old_dir_x * sin(SPEED) + cub->player->dir_y * cos(SPEED);
		cub->player->plane_x = cub->player->plane_x * cos(SPEED) - cub->player->plane_y * sin(SPEED);
		cub->player->plane_y = old_plane_x * sin(SPEED) + cub->player->plane_y * cos(SPEED);
	}
	if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_D))
	{
		cub->player->dir_x = cub->player->dir_x * cos(-SPEED) - cub->player->dir_y * sin(-SPEED);
		cub->player->dir_y = old_dir_x * sin(-SPEED) + cub->player->dir_y * cos(-SPEED);
		cub->player->plane_x = cub->player->plane_x * cos(-SPEED) - cub->player->plane_y * sin(-SPEED);
		cub->player->plane_y = old_plane_x * sin(-SPEED) + cub->player->plane_y * cos(-SPEED);
	}
	return (old_dir_x != cub->player->dir_x || old_plane_x != cub->player->plane_x);
}

void	player_walk(mlx_key_data_t key, void *param)
{
	t_cub *cub = (t_cub *)param;

	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(cub->mlx->mlx);
	if (up_down(cub) || left_right(cub))
	{
		draw_map(cub);
		printf("Player position: x = %d, y = %d\n", (int)cub->player->x, (int)cub->player->y);
	}
}
