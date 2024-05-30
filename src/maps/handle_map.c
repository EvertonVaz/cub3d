/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:11:26 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/30 14:26:02 by etovaz           ###   ########.fr       */
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
	char	*trim;
	int		i;

	trim = ft_strtrim(line, " ");
	map = NULL;
	if (trim && (trim[0] == '1' || trim[0] == '0'))
	{
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
	}
	free(trim);
	return (map);
}

int	check_map_infos(char *line, t_map *map)
{
	char	**splited_line;
	char	*trim;

	splited_line = ft_split(line, ' ');
	trim = ft_strtrim(splited_line[0], " WAESONCF\n");
	if (trim && *trim)
		map->checker->check_infos = 1;
	free(trim);
	free_split(splited_line);
	return(map->checker->check_infos);
}

t_map	*fill_map_infos(int fd)
{
	t_map	*map;
	char	*line;

	map = get_map_address(NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (map->map || !line)
			return (map);
		handle_texture(&map, line);
		if (ft_strchr(line, 'C'))
			map->ceiling_color = get_colors(&map, line, 'C');
		else if (ft_strchr(line, 'F'))
			map->floor_color = get_colors(&map, line, 'F');
		else
			map->map = handle_map(line, fd);
		check_map_infos(line, map);
		free(line);
	}
	return (NULL);
}
