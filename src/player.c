/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:42:27 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/10 17:07:40 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	player_direction(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (direction == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (direction == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (direction == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
}

void	get_player_posicion(t_cub *cub, int x, int y)
{
	if (cub->map[y][x] == 'N' || cub->map[y][x] == 'S'
		|| cub->map[y][x] == 'W' || cub->map[y][x] == 'E')
	{
		player_direction(cub->player, cub->map[y][x]);
		cub->player->direction = cub->map[y][x];
		cub->player->x = x;
		cub->player->y = y;
		cub->map[y][x] = '0';
	}
}