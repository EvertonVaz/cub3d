/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:29:42 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/05 18:06:31 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	check_directional(int y, int x)
{
	t_map	*map;

	map = get_map_address(NULL);
	if(map->map[y][x + 1] < '0' || map->map[y][x + 1] > '1') // olhando para a direita
		handle_error("olhando para a direita\n", 0);
	if(map->map[y][x - 1] < '0' || map->map[y][x - 1] > '1') // olhando para a esquerda
		handle_error("olhando para a esquerda\n", 0);
	if(map->map[y + 1][x] < '0' || map->map[y + 1][x] > '1') // olhando para baixo
		handle_error("para baixo\n", 0);
	if(map->map[y - 1][x] < '0' || map->map[y - 1][x] > '1') // olhando para cima
		handle_error("para cima\n", 0);
}

void	check_diagonal(int y, int x)
{
	t_map	*map;

	map = get_map_address(NULL);
	if(map->map[y - 1][x - 1] < '0' || map->map[y - 1][x - 1] > '1') // olhando para a diagonal esquerda superior
		handle_error("diagonal sup esq\n", 0);
	if(map->map[y - 1][x + 1] < '0' || map->map[y - 1][x + 1] > '1') // olhando para a diagonal direita superior
		handle_error("diagonal sup dir\n", 0);
	if(map->map[y + 1][x - 1] < '0' || map->map[y + 1][x - 1] > '1') // olhando para a diagonal esquerda inferior
		handle_error("diagonal inf esq\n", 0);
	if(map->map[y + 1][x + 1] < '0' || map->map[y + 1][x + 1] > '1') // olhando para a diagonal direita inferior
		handle_error("diagonal inf dir\n", 0);
}

void	check_walls(t_map *map)
{
	int width;
	int	height;
	int x;
	int y;

	y = -1;
	height = map->map_height - 1;
	while(map->map[++y])
	{
		x = 0;
		width = ft_strlen(map->map[y]) - 1;
		while(x < width)
		{
			if(map->map[y][x] == '0')
			{
				if((y == 0 || y == height) || (x == 0 || x == width))
					handle_error("verificando os extremos\n", 0);
				check_directional(y, x);
				check_diagonal(y, x);
			}
			x++;
		}
	}
}
