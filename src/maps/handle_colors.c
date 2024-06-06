/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:46:53 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/06 11:30:29 by egeraldo         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (colors[i])
	{
		if (!ft_isnum(colors[i]))
			return (0);
		i++;
	}
	return (1);
}

int32_t	get_colors(t_cub **cub, char *line, char identifier)
{
	int		i;
	char	**colors;
	int32_t	color;

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
	if (i == 3 && check_color(colors))
		color = save_colors(colors, cub, identifier);
	free_split(colors);
	return (color);
}

int32_t	save_colors(char **colors, t_cub **cub, char identifier)
{
	int32_t	red;
	int32_t	green;
	int32_t	blue;

	red = ft_atoi(colors[0]);
	green = ft_atoi(colors[1]);
	blue = ft_atoi(colors[2]);
	if (identifier == 'F')
		(*cub)->checker->check_floor++;
	else if (identifier == 'C')
		(*cub)->checker->check_ceiling++;
	return (ft_pixel(red, green, blue, 255));
}
