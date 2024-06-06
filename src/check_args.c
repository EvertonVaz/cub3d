/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:11:11 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/06 14:18:35 by egeraldo         ###   ########.fr       */
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

t_cub	*init_data(void)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	cub->map_width = 0;
	cub->map_height = 0;
	cub->we_texture = NULL;
	cub->so_texture = NULL;
	cub->no_texture = NULL;
	cub->ea_texture = NULL;
	cub->map = NULL;
	cub->ceiling_color = -1;
	cub->floor_color = -1;
	cub->checker = malloc(sizeof(t_checker));
	init_checker(cub->checker);
	cub->player = malloc(sizeof(t_player));
	init_player(cub->player);
	cub->screen = malloc(sizeof(t_screen));
	return (get_map_address(cub));
}

t_cub	*check_args_init_data(int argc, char **argv)
{
	t_cub	*cub;
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
	cub = init_data();
	cub->path_map = path_map;
	return (cub);
}
