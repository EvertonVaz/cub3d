/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:00:15 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/27 19:08:00 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include <stdint.h>

typedef struct s_player
{
	double	x;
}			t_player;

typedef struct s_map
{
	char	**map;
	int		map_width;
	int		map_height;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int32_t	floor_color;
	int32_t	ceiling_color;
}			t_map;

typedef struct s_texture_map {
    char *identifier;
    char **texture;
} t_texture_map;

#endif