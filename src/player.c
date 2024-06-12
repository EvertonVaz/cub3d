/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:42:27 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/12 16:21:56 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	phill_direction(double plax, double play, double dirx, double diry)
{
	t_player	*player;

	player = get_address(NULL)->player;
	player->plane_x = plax;
	player->plane_y = play;
	player->dir_x = dirx;
	player->dir_y = diry;
}

void	player_direction(char direction)
{
	if (direction == 'N')
		return(phill_direction(0.66, 0, 0, -1));
	if (direction == 'S')
		return(phill_direction(-0.66, 0, 0, 1));
	if (direction == 'E')
		return(phill_direction(0, 0.66, 1, 0));
	if (direction == 'W')
		return(phill_direction(0, -0.66, -1, 0));
}

void	get_player_posicion(t_cub *cub, int x, int y)
{
	char	*side;

	side = "NSWE";
	if (ft_strchr(side, cub->map[y][x]))
	{
		cub->checker->check_player++;
		player_direction(cub->map[y][x]);
		cub->player->direction = cub->map[y][x];
		cub->player->x = (double)x + 0.5;
		cub->player->y = (double)y + 0.5;
		cub->map[y][x] = '0';
	}
}
