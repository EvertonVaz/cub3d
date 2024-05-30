/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:46:53 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/30 16:57:28 by natali           ###   ########.fr       */
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
		if (!ft_is_space(line[i]))
			break ;
		i++;
	}
	return (i);
}

int32_t	get_colors(t_map **map, char *line, char identifier)
{
	int		i;
	char	**colors;
	int32_t	color;

	if (line[1])
		line++;
	i = pass_spaces(line);
	colors = ft_split(&line[i], ',');
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
	if (i == 3)
		color = ft_pixel(ft_atoi(colors[1]), ft_atoi(colors[2]), ft_atoi(colors[3]),
			255);
	free_split(colors);
	if (identifier == 'F')
		(*map)->checker->check_floor++;
	else if (identifier == 'C')
		(*map)->checker->check_ceiling++;
	return (color);
}

void check_colors(t_map **map)
{
	if ((*map)->floor_color == -1 || (*map)->ceiling_color == -1)
		handle_error("Error\nInvalid or unset color, please provide 3 numbers between 0 to 255\n", 0);
}