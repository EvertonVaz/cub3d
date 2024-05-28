/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:13:20 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/28 15:30:35 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_maps(t_map **map)
{
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
	if (map && *map)
		free(*map);
}

int	handle_error(char *msg, int num)
{
	t_map	*map;

	map = get_map_address(NULL);
	if (num < 0)
	{
		free_maps(&map);
		exit(write(2, msg, ft_strlen(msg)));
	}
	return (num);
}