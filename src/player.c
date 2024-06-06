/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:42:27 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/06 11:33:32 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	get_player_posicion(t_cub *cub, int x, int y)
{
	if (cub->map[y][x] == 'N' || cub->map[y][x] == 'S'
		|| cub->map[y][x] == 'W' || cub->map[y][x] == 'E')
	{
		cub->player->direction = cub->map[y][x];
		cub->player->x = x;
		cub->player->y = y;
		cub->map[y][x] = '0';
	}
}
