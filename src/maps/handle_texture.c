/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:56:59 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/27 13:17:08 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	fill_texture(t_map **map, char *line)
{
	char	**splited_line;

	splited_line = ft_split(line, ' ');
	if (ft_strnstr(splited_line[0], "WE", ft_strlen(splited_line[0])))
	{
		(*map)->we_texture = splited_line[1];
		return (1);
	}
	if (ft_strnstr(splited_line[0], "SO", ft_strlen(splited_line[0])))
	{
		(*map)->so_texture = splited_line[1];
		return (1);
	}
	if (ft_strnstr(splited_line[0], "NO", ft_strlen(splited_line[0])))
	{
		(*map)->no_texture = splited_line[1];
		return (1);
	}
	if (ft_strnstr(splited_line[0], "EA", ft_strlen(splited_line[0])))
	{
		(*map)->ea_texture = splited_line[1];
		return (1);
	}
	free_split(splited_line);
	return (0);
}

int	validate_texture_path(t_map map)
{
	int			fd;
	int			i;
	const char	*paths[4] = {map.we_texture, map.so_texture, map.no_texture, map.ea_texture};

	i = 0;
	if (!map.we_texture || !map.so_texture || !map.no_texture || !map.ea_texture)
		return (0);
	while (paths[i])
	{
		fd = open(paths[i], O_RDONLY);
		if (fd < 0)
			return (0);
		close(fd);
		i++;
	}
	return (1);
}
