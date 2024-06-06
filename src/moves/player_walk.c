/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:19:42 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/06 17:39:34 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	up_down(t_cub *cub)
{
	mlx_t	*mlx;
	int		x;
	int		y;

	mlx = cub->screen->mlx;
	x = cub->player->x;
	y = cub->player->y;
	if (mlx_is_key_down(mlx, MLX_KEY_W) && cub->map[y - 1][x] != '1')
		cub->player->y--;
	else if (mlx_is_key_down(mlx, MLX_KEY_S) && cub->map[y + 1][x] != '1')
		cub->player->y++;
	else if (mlx_is_key_down(mlx, MLX_KEY_A) && cub->map[y][x - 1] != '1')
		cub->player->x--;
	else if (mlx_is_key_down(mlx, MLX_KEY_D) && cub->map[y][x + 1] != '1')
		cub->player->x++;
	return (y != cub->player->y || x != cub->player->x);
}

int	left_right(t_cub *cub)
{
	mlx_t	*mlx;
	int		x;
	int		y;

	mlx = cub->screen->mlx;
	x = cub->player->x;
	y = cub->player->y;
	if (mlx_is_key_down(mlx, MLX_KEY_A) && cub->map[y][x - 1] != '1')
		cub->player->x--;
	else if (mlx_is_key_down(mlx, MLX_KEY_D) && cub->map[y][x + 1] != '1')
		cub->player->x++;
	return (x != cub->player->x);
}

void	player_walk(mlx_key_data_t key, void *param)
{
	t_cub *cub = (t_cub *)param;

	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(cub->screen->mlx);
	// cub->player->render = up_down(cub);
	if (up_down(cub))
	{
		draw_map(cub);
		printf("Player position: x = %d, y = %d\n", cub->player->x, cub->player->y);
	}
}