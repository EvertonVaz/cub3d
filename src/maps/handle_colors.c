/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:46:53 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/02 11:57:56 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	pass_spaces(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (ft_isdigit(line[i]))
			break ;
		i++;
	}
	return (i);
}

int	check_color(char **colors)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (colors[i])
	{
		while (colors[i][j])
		{
			if (!ft_isdigit(colors[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int32_t	get_colors(t_map **map, char *line, char identifier)
{
	int		i;
	char	**colors;
	int32_t	color;
	char	*trim_line;

	i = pass_spaces(line);
	trim_line = ft_strtrim(line, "\n");
	colors = ft_split(&trim_line[i], ',');
	free(trim_line);
	i = -1;
	color = -1;
	while (colors[++i])
	{
		if (ft_atoi(colors[i]) < 0 || ft_atoi(colors[i]) > 255)
		{
			free_split(colors);
			return (color);
		}
	}
	if (i == 3 && check_color(colors))
		save_colors(colors, &color, map, identifier);
	free_split(colors);
	return (color);
}

void	save_colors(char **colors, int32_t *color, t_map **map, char identifier)
{
	*color = ft_pixel(ft_atoi(colors[0]), ft_atoi(colors[1]),
			ft_atoi(colors[2]), 255);
	if (identifier == 'F')
		(*map)->checker->check_floor++;
	else if (identifier == 'C')
		(*map)->checker->check_ceiling++;
}
