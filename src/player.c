/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:42:27 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/06 09:46:37 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	get_player_posicion(t_map *map, int x, int y)
{
	if (map->map[y][x] == 'N' || map->map[y][x] == 'S'
		|| map->map[y][x] == 'W' || map->map[y][x] == 'E')
	{
		map->player->direction = map->map[y][x];
		map->player->x = x;
		map->player->y = y;
		map->map[y][x] = '0';
	}
}
