/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:46:53 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/24 17:50:30 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int	check_color(char *color)
{
	int	n;
	if (!color)
		return (-1);
	n = ft_atoi(color);
	return (n >= 0 && n <= 255);
}

int32_t	get_colors(char *line)
{
	char	**colors;
	int32_t	color;
	int		check;

	color = 0;
	colors = ft_split(line, ' ');
	if (check_color(colors[1]) && check_color(colors[2]) && check_color(colors[3]))
	{
		color = ft_pixel(ft_atoi(colors[1]), ft_atoi(colors[2]), ft_atoi(colors[3]), 255);
		free_split(colors);
		return (color);
	}
	free_split(colors);
	return (-1);
}