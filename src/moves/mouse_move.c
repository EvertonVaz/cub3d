/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:08:05 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/13 17:30:03 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	mouse_rotate(double xpos, double ypos, t_cub *cub)
{
	static double	old_x;
	double			dirx;
	double			diry;
	double			delta_x;
	double			sensitivity;

	(void)ypos;
	old_x = 1;
	sensitivity = 0.008;
	dirx = cub->player->dir_x;
	diry = cub->player->dir_y;
	if (old_x < 0)
		old_x = xpos;
	delta_x = xpos - old_x;
	if (delta_x != 0)
	{
		rotate_player(cub->player, delta_x * sensitivity);
		old_x = xpos;
	}
	return (cub->player->dir_x != dirx || cub->player->dir_y != diry);
}

void	mouse_move(double xpos, double ypos, void *param)
{
	if (mouse_rotate(xpos, ypos, (t_cub *)param))
		render((t_cub *)param);
}