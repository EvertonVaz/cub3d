/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:11:11 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/06 10:07:00 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_checker(t_checker *checker)
{
	checker->check_we = 0;
	checker->check_so = 0;
	checker->check_no = 0;
	checker->check_ea = 0;
	checker->check_ceiling = 0;
	checker->check_floor = 0;
	checker->check_infos = 0;
}

void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->direction = 0;
}

t_map	*init_data(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->screen_width = 1200;
	map->screen_height = 800;
	map->map_width = 0;
	map->map_height = 0;
	map->we_texture = NULL;
	map->so_texture = NULL;
	map->no_texture = NULL;
	map->ea_texture = NULL;
	map->map = NULL;
	map->ceiling_color = -1;
	map->floor_color = -1;
	map->checker = malloc(sizeof(t_checker));
	init_checker(map->checker);
	map->player = malloc(sizeof(t_player));
	init_player(map->player);
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
