/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:19:42 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/13 15:28:26 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	walk(t_cub *cub, double new_x, double new_y)
{
	double	x;
	double	y;

	x = cub->player->x;
	y = cub->player->y;
	if (cub->map[(int)y][(int)new_x] != '1')
		cub->player->x = new_x;
	if (cub->map[(int)new_y][(int)x] != '1')
		cub->player->y = new_y;
}

int	up_down(t_cub *cub)
{
	double	    x;
	double	    y;
    t_player    *player;

	x = cub->player->x;
	y = cub->player->y;
    p = cub->player;
	if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_W))
		walk(cub, x + cub->player->dir_x * SPEED, y + cub->player->dir_y
			* SPEED);
	else if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_S))
		walk(cub, x - cub->player->dir_x * SPEED, y - cub->player->dir_y
			* SPEED);
	if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_A))
		walk(cub, x - cub->player->plane_x * SPEED, y - cub->player->plane_y
			* SPEED);
	else if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_D))
		walk(cub, x + cub->player->plane_x * SPEED, y + cub->player->plane_y
			* SPEED);
	return (y != cub->player->y || x != cub->player->x);
}

void	rotate_player(t_player *player, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed) - player->dir_y
		* sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed) - player->plane_y
		* sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed) + player->plane_y
		* cos(rot_speed);
}

int	rotate(t_cub *cub)
{
	double	dirx;
	double	diry;

	dirx = cub->player->dir_x;
	diry = cub->player->dir_y;
	if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_RIGHT))
		rotate_player(cub->player, SPEED);
	else if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_LEFT))
		rotate_player(cub->player, -SPEED);
	return (cub->player->dir_x != dirx || cub->player->dir_y != diry);
}

void	player_walk(mlx_key_data_t key, void *param)
{
	t_cub	*cub;
	int		moviment;

	cub = (t_cub *)param;
	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(cub->mlx->mlx);
	moviment = rotate(cub) || up_down(cub);
	if (moviment)
		render(cub);
}
