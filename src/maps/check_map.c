/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:29:42 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/17 11:50:53 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	check_directional(int y, int x)
{
	t_cub	*cub;

	cub = get_address(NULL);
	if (cub->map[y][x + 1] < '0' || cub->map[y][x + 1] > '1')
		handle_error("Error\nInvalid map, an open wall found to the right\n",
			0);
	if (cub->map[y][x - 1] < '0' || cub->map[y][x - 1] > '1')
		handle_error("Error\nInvalid map, an open wall found to the left\n", 0);
	if (cub->map[y + 1][x] < '0' || cub->map[y + 1][x] > '1')
		handle_error("Error\nInvalid map, an open wall found below\n", 0);
	if (cub->map[y - 1][x] < '0' || cub->map[y - 1][x] > '1')
		handle_error("Error\nInvalid map, an open wall found above\n", 0);
}

void	check_diagonal(int y, int x)
{
	t_cub	*cub;

	cub = get_address(NULL);
	if (cub->map[y - 1][x - 1] < '0' || cub->map[y - 1][x - 1] > '1')
		handle_error("Error\nInvalid map,\
 one upper left diagonal wall is open.\n", 0);
	if (cub->map[y - 1][x + 1] < '0' || cub->map[y - 1][x + 1] > '1')
		handle_error("Error\nInvalid map,\
 one upper right diagonal wall is open.\n", 0);
	if (cub->map[y + 1][x - 1] < '0' || cub->map[y + 1][x - 1] > '1')
		handle_error("Error\nInvalid map,\
 one lower left diagonal wall is open.\n", 0);
	if (cub->map[y + 1][x + 1] < '0' || cub->map[y + 1][x + 1] > '1')
		handle_error("Error\nInvalid map,\
 one lower right diagonal wall is open.\n", 0);
}

void	check_walls(t_cub *cub)
{
	int	width;
	int	height;
	int	x;
	int	y;

	y = -1;
	height = cub->map_height - 1;
	while (cub->map[++y])
	{
		x = 0;
		width = ft_strlen(cub->map[y]) - 1;
		while (x < width)
		{
			if (cub->map[y][x] == '0')
			{
				if ((y == 0 || y == height) || (x == 0 || x == width))
					handle_error("Error\nInvalid map, check the edges.\n", 0);
				check_directional(y, x);
				check_diagonal(y, x);
			}
			x++;
		}
	}
}
