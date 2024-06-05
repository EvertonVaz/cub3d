/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:11:11 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/05 17:21:52 by egeraldo         ###   ########.fr       */
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
	map->player = malloc(sizeof(t_player));
	map->player->x = -1;
	map->player->y = -1;
	return (get_map_address(map));
}

void	check_args_return_path_map(int argc, char **argv, t_map **map)
{
	char	*path_map;

	if (argc != 2)
	{
		printf("You need 1 and only 1 file with instructions\n");
		exit(1);
	}
	path_map = ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]));
	if (path_map && !ft_strchr(argv[1], '/'))
		path_map = ft_strjoin("./assets/maps/", argv[1], 0);
	else
		path_map = ft_strdup(argv[1]);
	*map = init_data();
	(*map)->path_map = path_map;
}
