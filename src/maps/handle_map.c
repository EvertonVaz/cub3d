/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:11:26 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/06 11:29:59 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_cub	*get_map_address(t_cub *cub)
{
	static t_cub	*map_address;

	if (!map_address)
		map_address = cub;
	return (map_address);
}

t_cub	*fill_width_height(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			get_player_posicion(cub, x, y);
			x++;
		}
		if (cub->map_width < x)
			cub->map_width = x;
		y++;
	}
	cub->map_height = y;
	return (cub);
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
			if (ft_strchr(line, '\n'))
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

void	check_map_infos(char *line, t_cub *cub)
{
	char	**splited_line;
	char	*trim;

	if (!line)
		return ;
	splited_line = ft_split(line, ' ');
	trim = ft_strtrim(splited_line[0], " WAESONCF\n");
	if (trim && *trim)
		cub->checker->check_infos = 1;
	free(trim);
	free_split(splited_line);
}

t_cub	*fill_map_infos(int fd, t_cub *cub)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (cub);
		line[ft_strlen(line) - 1] = '\0';
		handle_texture(&cub, line);
		if (ft_strchr(line, 'C'))
			cub->ceiling_color = get_colors(&cub, line, 'C');
		else if (ft_strchr(line, 'F'))
			cub->floor_color = get_colors(&cub, line, 'F');
		else
			cub->map = handle_map(line, fd);
		if (cub->map)
			return (fill_width_height(cub));
		check_map_infos(line, cub);
		free(line);
	}
	return (NULL);
}
