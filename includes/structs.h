/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:00:15 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/08 10:56:48 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>
# include "../libs/MLX42/include/MLX42/MLX42.h"

# define WIDTH 1200
# define HEIGHT 900

typedef struct s_player
{
	int			x;
	int			y;
	int			direction;
	int			dir_x;
	int			dir_y;
}				t_player;

typedef struct s_checker
{
	int			check_no;
	int			check_we;
	int			check_so;
	int			check_ea;
	int			check_floor;
	int			check_ceiling;
	int			check_infos;
}				t_checker;

typedef struct s_screen
{
	mlx_t			*mlx;
	mlx_image_t		*img;
}				t_screen;

typedef struct s_cub
{
	char		*path_map;
	char		**map;
	int			map_width;
	int			map_height;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int32_t		floor_color;
	int32_t		ceiling_color;
	t_screen	*screen;
	t_checker	*checker;
	t_player	*player;
}				t_cub;


typedef struct s_texture_map
{
	char		*identifier;
	char		**texture;
	int			*check;
}				t_texture_map;

#endif