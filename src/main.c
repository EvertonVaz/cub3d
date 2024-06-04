/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:13:45 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/03 20:58:50 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_map	*init_data(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->we_texture = NULL;
	map->so_texture = NULL;
	map->no_texture = NULL;
	map->ea_texture = NULL;
	map->map = NULL;
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->checker = malloc(sizeof(t_checker));
	map->checker->check_we = 0;
	map->checker->check_so = 0;
	map->checker->check_no = 0;
	map->checker->check_ea = 0;
	map->checker->check_ceiling = 0;
	map->checker->check_floor = 0;
	map->checker->check_infos = 0;
	return (get_map_address(map));
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	map = NULL;
	check_args_return_path_map(argc, argv, &map);
	fd = open(map->path_map, O_RDONLY);
	handle_error(NULL, fd);
	map = fill_map_infos(fd);
	handle_error(check_duplicates(map), 0);
	validate_texture(&map);
	printf("%s\n", map->path_map);
	free_maps(&map);
	return (0);
}
