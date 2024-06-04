/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:56:59 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/03 21:05:45 by natali           ###   ########.fr       */
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
				*texture_map[i].texture = texture;
			*texture_map[i].check = *texture_map[i].check + 1;
			return (*texture_map[i].check - 1);
		}
		i++;
	}
	return (1);
}

int	handle_texture(t_map **map, char *line)
{
	char	**splited_line;
	char	*texture;
	int		is_texture;
	char	*trim_line;

	trim_line = ft_strtrim(line, "\n");
	splited_line = ft_split(trim_line, ' ');
	free(trim_line);
	is_texture = 1;
	if (splited_line && splited_line[0] && splited_line[1])
	{
		splited_line[1][ft_strlen(splited_line[1])] = '\0';
		//tinha um -1 aqui, não sei pq, mas tirei pq tava comendo a última letra do path
		texture = ft_strdup(splited_line[1]);
		if (fill_texture(map, splited_line[0], texture))
			free(texture);
	}
	if (ft_strchr(splited_line[0], 'F') || ft_strchr(splited_line[0], 'C'))
		is_texture = 0;
	free_split(splited_line);
	return (is_texture);
}

void validate_texture(t_map **map)
{
	int fd;

	fd = open((*map)->no_texture, O_RDONLY);
	handle_error(NULL, fd);
	fd = open((*map)->we_texture, O_RDONLY);
	handle_error(NULL, fd);
	fd = open((*map)->so_texture, O_RDONLY);
	handle_error(NULL, fd);
	fd = open((*map)->ea_texture, O_RDONLY);
	handle_error(NULL, fd);
//precisamos melhorar a função de erro pra essa situação, pra explicar onde está o erro de permissão e não ficar confuso
}