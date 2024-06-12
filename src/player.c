/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:42:27 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/12 12:56:36 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	player_direction(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->plane_x = 0.66;
		player->plane_y = 0;
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (direction == 'S')
	{
		player->plane_x = -0.66;
		player->plane_y = 0;
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (direction == 'E')
	{
		player->plane_x = 0;
		player->plane_y = 0.66;
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (direction == 'W')
	{
		player->plane_x = 0;
		player->plane_y = -0.66;
		player->dir_x = -1;
		player->dir_y = 0;
	}
}

void	get_player_posicion(t_cub *cub, int x, int y)
{
	if (cub->map[y][x] == 'N' || cub->map[y][x] == 'S'
		|| cub->map[y][x] == 'W' || cub->map[y][x] == 'E')
	{
		cub->checker->check_player++;
		player_direction(cub->player, cub->map[y][x]);
		cub->player->direction = cub->map[y][x];
		cub->player->x = (double)x;
		cub->player->y = (double)y;
		cub->map[y][x] = '0';
	}
}
