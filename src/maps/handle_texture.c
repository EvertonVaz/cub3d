/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:56:59 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/05 10:04:37 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*check_side(char *identifier, char *side)
{
	return (ft_strnstr(identifier, side, ft_strlen(identifier)));
}

int	verify_texture_path(char*texture)
{
	int fd;

	fd = open(texture, O_RDONLY);
	close(fd);
	if (fd < 0)
		return (-10);
	return (1);
}

void	fill_texture(t_map **map, char *side, char *texture)
{
	int					i;
	const t_texture_map	texture_map[5] = {{"WE", &(*map)->we_texture,
		&(*map)->checker->check_we}, {"SO", &(*map)->so_texture,
		&(*map)->checker->check_so}, {"NO", &(*map)->no_texture,
		&(*map)->checker->check_no}, {"EA", &(*map)->ea_texture,
		&(*map)->checker->check_ea}, {NULL, NULL, NULL}};

	i = 0;
	while (texture_map[i].identifier && side)
	{
		if (check_side(texture_map[i].identifier, side))
		{
			if (*texture_map[i].check == 0)
				*texture_map[i].texture = ft_strdup(texture);
			*texture_map[i].check = *texture_map[i].check + verify_texture_path(texture);
		}
		i++;
	};
}

int	handle_texture(t_map **map, char *line)
{
	char	**splited_line;
	int		is_texture;

	splited_line = ft_split(line, ' ');
	is_texture = 1;
	if (splited_line && splited_line[0] && splited_line[1])
		fill_texture(map, splited_line[0], splited_line[1]);
	if (ft_strchr(splited_line[0], 'F') || ft_strchr(splited_line[0], 'C'))
		is_texture = 0;
	free_split(splited_line);
	return (is_texture);
}
