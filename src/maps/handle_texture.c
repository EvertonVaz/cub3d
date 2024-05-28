/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:56:59 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/28 09:02:20 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*check_side(char *identifier, char *side)
{
	return (ft_strnstr(identifier, side, ft_strlen(identifier)));
}

void	fill_texture(t_map **map, char *side, char *texture)
{
	int					i;
	const t_texture_map	texture_map[5] = {
	{"WE", &(*map)->we_texture},
	{"SO", &(*map)->so_texture},
	{"NO", &(*map)->no_texture},
	{"EA", &(*map)->ea_texture},
	{NULL, NULL}
	};

	i = 0;
	while (texture_map[i].identifier)
	{
		if (check_side(texture_map[i].identifier, side))
		{
			*texture_map[i].texture = texture;
			break ;
		}
		i++;
	}
}

char	*handle_texture(t_map **map, char *line)
{
	char			**splited_line;

	splited_line = ft_split(line, ' ');
	if (splited_line && splited_line[0] && splited_line[1])
	{
		splited_line[1][ft_strlen(splited_line[1]) - 1] = '\0';
		fill_texture(map, splited_line[0], ft_strdup(splited_line[1]));
	}
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
