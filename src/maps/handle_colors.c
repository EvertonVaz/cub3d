/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:46:53 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/27 18:23:20 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	get_colors(char *line)
{
	int		i;
	char	**colors;
	int32_t	color;

	while (line && *line)
	{
		if (ft_isdigit(*line))
			break ;
		line++;
	}
	colors = ft_split(line, ',');
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
	color = ft_pixel(ft_atoi(colors[1]), ft_atoi(colors[2]), ft_atoi(colors[3]),
			255);
	free_split(colors);
	return (color);
}
