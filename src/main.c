/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:13:45 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/27 18:41:02 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	handle_error(char *msg, int num)
{
	if (num < 0)
		exit(write(2, msg, ft_strlen(msg)));
	return (num);
}

void	free_maps(t_map **map)
{
	free((*map)->ea_texture);
	free((*map)->we_texture);
	free((*map)->no_texture);
	free((*map)->so_texture);
	free_split((*map)->map);
	free(*map);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	fd = check_args_return_fd(argc, argv);
	handle_error("Error: Invalid arguments\n", fd);
	map = fill_map_infos(fd);
	free_maps(&map);
	printf("%d\n", check_args_return_fd(argc, argv));
	return (0);
}