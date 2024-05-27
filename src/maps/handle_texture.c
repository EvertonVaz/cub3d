/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:56:59 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/27 20:58:23 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*check_side(char *splited_line, char *side)
{
	return (ft_strnstr(splited_line, side, ft_strlen(splited_line)));
}

// nao pode haver argumentos duplicados no arquivo do mapa
// void	check_duplicated(t_map map, char *splited_line, char *side)
// {
	// if (check_side(splited_line, side) && map.)
// }

char	*fill_texture(t_map **map, char *line)
{
	char	**splited_line;

	splited_line = ft_split(line, ' ');
	if (splited_line && splited_line[0] && splited_line[1])
		splited_line[1][ft_strlen(splited_line[1]) - 1] = '\0';
	else if (check_side(splited_line[0], "WE") && !(*map)->we_texture)
		(*map)->we_texture = ft_strdup(splited_line[1]);
	else if (check_side(splited_line[0], "SO") && !(*map)->so_texture)
		(*map)->so_texture = ft_strdup(splited_line[1]);
	else if (check_side(splited_line[0], "NO") && !(*map)->no_texture)
		(*map)->no_texture = ft_strdup(splited_line[1]);
	else if (check_side(splited_line[0], "EA") && !(*map)->ea_texture)
		(*map)->ea_texture = ft_strdup(splited_line[1]);
	free_split(splited_line);
	return (0);
}

int	validate_texture_path(t_map map)
{
	int		fd;
	int		i;
	char	*paths[4];

	paths[0] = map.we_texture;
	paths[1] = map.so_texture;
	paths[2] = map.no_texture;
	paths[3] = map.ea_texture;
	i = 0;
	if (!paths[0] || !paths[1] || !paths[2] || !paths[3])
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
