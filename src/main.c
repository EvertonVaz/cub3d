/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:13:45 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/05 17:23:27 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
	check_walls(map);
	printf("%s\n", map->path_map);
	free_maps(&map);
	return (0);
}
