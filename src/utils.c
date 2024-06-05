/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:13:20 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/05 17:22:02 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_maps(t_map **map)
{
	if (map && (*map)->path_map)
		free((*map)->path_map);
	if (map && (*map)->ea_texture)
		free((*map)->ea_texture);
	if (map && (*map)->we_texture)
		free((*map)->we_texture);
	if (map && (*map)->no_texture)
		free((*map)->no_texture);
	if (map && (*map)->so_texture)
		free((*map)->so_texture);
	if (map && (*map)->map)
		free_split((*map)->map);
	if (map && (*map)->checker)
		free((*map)->checker);
	if (map && (*map)->player)
		free((*map)->player);
	if (map && *map)
		free(*map);
}

int	handle_error(char *msg, int num)
{
	t_map	*map;

	map = get_map_address(NULL);
	if (num == -1)
	{
		free_maps(&map);
		msg = ft_strjoin("Error\n", strerror(errno), 0);
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
		free(msg);
		exit(1);
	}
	if (msg)
	{
		free_maps(&map);
		write(2, msg, ft_strlen(msg));
		exit(1);
	}
	return (num);
}
