/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:19:42 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/12 08:55:45 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int up_down(t_cub *cub) {
    double new_x;
    double new_y;
    double x;
    double y;
    double dir_x;
    double dir_y;

    x = cub->player->x;
    y = cub->player->y;
    dir_x = cub->player->dir_x;
    dir_y = cub->player->dir_y;

    if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_W)) {
        new_x = x + dir_x * SPEED;
        new_y = y + dir_y * SPEED;
        if (cub->map[(int)y][(int)new_x] != '1') {
            cub->player->x = new_x;
        }
        if (cub->map[(int)new_y][(int)x] != '1') {
            cub->player->y = new_y;
        }
    } else if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_S)) {
        new_x = x - dir_x * SPEED;
        new_y = y - dir_y * SPEED;
        if (cub->map[(int)y][(int)new_x] != '1') {
            cub->player->x = new_x;
        }
        if (cub->map[(int)new_y][(int)x] != '1') {
            cub->player->y = new_y;
        }
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
