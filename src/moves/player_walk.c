/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:19:42 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/11 10:03:00 by egeraldo         ###   ########.fr       */
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
		printf("é parede X? %c\n", cub->map[(int)(y + dir_y * SPEED)][(int)x]);
		if (cub->map[(int)(y + dir_y * SPEED)][(int)cub->player->x] == '0')
			cub->player->x += cub->player->dir_x * SPEED;
		printf("é parede Y? %c\n", cub->map[(int)y][(int)(x + dir_x * SPEED)]);
		if (cub->map[(int)cub->player->y][(int)(x + dir_x * SPEED)] == '0')
			cub->player->y += cub->player->dir_y * SPEED;
	}
	else if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_S))
	{
		if (cub->map[(int)(y - dir_y * SPEED)][(int)cub->player->x] == '0')
			cub->player->x -= cub->player->dir_x * SPEED;
		if (cub->map[(int)cub->player->y][(int)(x - dir_x * SPEED)] == '0')
			cub->player->y -= cub->player->dir_y * SPEED;
	}
	return (y != cub->player->y || x != cub->player->x);
}

void rotate_player(t_player *player, double rot_speed)
{
    double old_dir_x;
    double old_plane_x;

	old_dir_x = player->dir_x;
    player->dir_x = player->dir_x * cos(rot_speed) - player->dir_y * sin(rot_speed);
    player->dir_y = old_dir_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
    player->plane_x = player->plane_x * cos(rot_speed) - player->plane_y * sin(rot_speed);
    player->plane_y = old_plane_x * sin(rot_speed) + player->plane_y * cos(rot_speed);
}

int	rotate(t_cub *cub)
{
    if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_A))
        rotate_player(cub->player, SPEED);
    else if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_D))
        rotate_player(cub->player, -SPEED);
    return (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_A) || mlx_is_key_down(cub->mlx->mlx, MLX_KEY_D));
}

void	player_walk(mlx_key_data_t key, void *param)
{
	t_cub *cub = (t_cub *)param;

	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(cub->mlx->mlx);
	if (up_down(cub) || rotate(cub))
	{
		draw_map(cub);
		printf("Player position: x = %d, y = %d\n", (int)cub->player->x, (int)cub->player->y);
		printf("Player direction: x = %f, y = %f\n", cub->player->dir_x, cub->player->dir_y);
		printf("Player plane: x = %f, y = %f\n", cub->player->plane_x, cub->player->plane_y);
	}
}
