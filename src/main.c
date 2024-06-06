/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:13:45 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/06 09:49:36 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_map	*get_map_infos()
{
	t_map	*map;
	int		fd;

	map = get_map_address(NULL);
	fd = open(map->path_map, O_RDONLY);
	handle_error(NULL, fd);
	map = fill_map_infos(fd);
	handle_error(check_duplicates(map), 0);
	check_walls(map);
	close(fd);
	map->map[map->player->y][map->player->x] = map->player->direction;
	return (map);
}

void	print_map(t_map *map)
{
	int	y;

	y = -1;
	while (map->map[++y])
		printf("%s\n", map->map[y]);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	check_args_return_path_map(argc, argv, &map);
	map = get_map_infos();
	print_map(map);
	printf("O PROGRAMA CHEGOU NO FIM! %s\n", map->path_map);
	free_maps(&map);
	return (0);
}
