/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:11:26 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/30 12:48:36 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_map	*get_map_address(t_map *map)
{
	static t_map	*map_address;

	if (!map_address)
		map_address = map;
	return (map_address);
}

char	**handle_map(char *line, int fd)
{
	char	**map;
	int		i;

	map = NULL;
	map = malloc(sizeof(char *) * 64);
	i = 0;
	while (1)
	{
		line[ft_strlen(line) - 1] = '\0';
		map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
		map[i] = NULL;
		if (!line)
			break ;
	}
	return (map);
}

t_map	*fill_map_infos(int fd)
{
	t_map	*map;
	char	*line;
	char	*trim;

	map = get_map_address(NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (map->map || !line)
			return (map);
		trim = ft_strtrim(line, " \n");
		if (handle_texture(&map, line))
			continue ;
		else if (ft_strchr(line, 'C'))
			map->ceiling_color = get_colors(&map, line, 'C');
		else if (ft_strchr(line, 'F'))
			map->floor_color = get_colors(&map, line, 'F');
		else if (trim && (trim[0] == '1' || trim[0] == '0'))
			map->map = handle_map(line, fd);
		// preciso checar se tem alguma informação invalida no mapa
		else if (trim && *trim && !ft_strchr(trim, '/'))
			map->checker->check_infos = 1;
		free(trim);
		free(line);
	}
	return (NULL);
}
