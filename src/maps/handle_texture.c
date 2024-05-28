/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:56:59 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/28 15:27:31 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*check_side(char *identifier, char *side)
{
	return (ft_strnstr(identifier, side, ft_strlen(identifier)));
}

int	fill_texture(t_map **map, char *side, char *texture)
{
	int					i;
	const t_texture_map	texture_map[5] = {
	{"WE", &(*map)->we_texture, &(*map)->check_we},
	{"SO", &(*map)->so_texture, &(*map)->check_so},
	{"NO", &(*map)->no_texture, &(*map)->check_no},
	{"EA", &(*map)->ea_texture, &(*map)->check_ea},
	{NULL, NULL, NULL}
	};

	i = 0;
	while (texture_map[i].identifier && side)
	{
		if (check_side(texture_map[i].identifier, side))
		{
			if (*texture_map[i].check == 0)
				*texture_map[i].texture = texture;
			*texture_map[i].check = *texture_map[i].check + 1;
			return (*texture_map[i].check - 1) ;
		}
		i++;
	}
	return (1);
}

char	*handle_texture(t_map **map, char *line)
{
	char	**splited_line;
	char	*texture;

	splited_line = ft_split(line, ' ');
	if (splited_line && splited_line[0] && splited_line[1])
	{
		splited_line[1][ft_strlen(splited_line[1]) - 1] = '\0';
		texture = ft_strdup(splited_line[1]);
		if (fill_texture(map, splited_line[0], texture))
			free(texture);
	}
	free_split(splited_line);
	return (0);
}
