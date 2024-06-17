/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:08:05 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/14 07:28:04 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	mouse_rotate(double xpos, double ypos, t_cub *cub)
{
	static double	old_x;
	double			dirx;
	double			delta_x;
	double			sensitivity;

	(void)ypos;
	sensitivity = 0.01;
	dirx = cub->player->dir_x;
	if (old_x < 0)
		old_x = xpos;
	delta_x = xpos - old_x;
	if (delta_x != 0)
	{
		rotate_player(cub->player, delta_x * sensitivity);
		old_x = xpos;
	}
	return (cub->player->dir_x != dirx);
}

void	mouse_move(double xpos, double ypos, void *param)
{
	if (mouse_rotate(xpos, ypos, (t_cub *)param))
		render((t_cub *)param);
}
