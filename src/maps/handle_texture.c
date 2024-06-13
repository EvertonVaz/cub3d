/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:56:59 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/13 10:49:52 by egeraldo         ###   ########.fr       */
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
	if (fd < 0)
		return (-10);
	close(fd);
	return (1);
}

void	fill_texture(t_cub **cub, char *side, char *texture)
{
	int					i;
	const t_texture_map	texture_map[5] = {
	{"WE", &(*cub)->we_texture, &(*cub)->checker->check_we},
	{"SO", &(*cub)->so_texture, &(*cub)->checker->check_so},
	{"NO", &(*cub)->no_texture, &(*cub)->checker->check_no},
	{"EA", &(*cub)->ea_texture, &(*cub)->checker->check_ea},
	{NULL, NULL, NULL}
	};

	i = 0;
	while (texture_map[i].identifier && side)
	{
		if (check_side(texture_map[i].identifier, side))
		{
			if (*texture_map[i].check == 0)
				*texture_map[i].texture = ft_strdup(texture);
			*texture_map[i].check += verify_texture_path(texture);
		}
		i++;
	};
}

int	handle_texture(t_cub **cub, char *line)
{
	char	**splited_line;
	int		is_texture;

	splited_line = ft_split(line, ' ');
	is_texture = 1;
	if (splited_line && splited_line[0] && splited_line[1])
		fill_texture(cub, splited_line[0], splited_line[1]);
	if (ft_strchr(splited_line[0], 'F') || ft_strchr(splited_line[0], 'C'))
		is_texture = 0;
	free_split(splited_line);
	return (is_texture);
}
