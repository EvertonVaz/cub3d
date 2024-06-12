/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:19:42 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/12 11:06:53 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void    walk(t_cub *cub, double new_x, double new_y)
{
    double  x;
    double  y;

    x = cub->player->x;
    y = cub->player->y;
    if (cub->map[(int)y][(int)new_x] != '1')
        cub->player->x = new_x;
    if (cub->map[(int)new_y][(int)x] != '1')
        cub->player->y = new_y;
}

int up_down(t_cub *cub)
{
    double  x;
    double  y;
    double  new_x;
    double  new_y;

    x = cub->player->x;
    y = cub->player->y;
    if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_W))
    {
        new_x = x + cub->player->dir_x * SPEED;
        new_y = y + cub->player->dir_y * SPEED;
        walk(cub, new_x, new_y);
    }
    else if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_S))
    {
        new_x = x - cub->player->dir_x * SPEED;
        new_y = y - cub->player->dir_y * SPEED;
        walk(cub, new_x, new_y);
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
        rotate_player(cub->player, -SPEED);
    else if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_D))
        rotate_player(cub->player, SPEED);
    return (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_A) || mlx_is_key_down(cub->mlx->mlx, MLX_KEY_D));
}

void	player_walk(mlx_key_data_t key, void *param)
{
	t_cub   *cub = (t_cub *)param;
    int     moviment;

	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(cub->mlx->mlx);
    moviment = rotate(cub) || up_down(cub);
	if (moviment)
		draw_map(cub);
}
