/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:13:45 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/30 11:12:31 by etovaz           ###   ########.fr       */
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
	map->check_we = 0;
	map->check_so = 0;
	map->check_no = 0;
	map->check_ea = 0;
	map->floor_check = 0;
	map->ceiling_check = 0;
	return (get_map_address(map));
}

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	map = init_data();
	map->path_map = check_args_return_path_map(argc, argv);
	fd = open(map->path_map, O_RDONLY);
	handle_error(NULL, fd);
	map = fill_map_infos(fd);
	handle_error(check_duplicates(map), 0);
	free_maps(&map);
	printf("%s\n", check_args_return_path_map(argc, argv));
	return (0);
}