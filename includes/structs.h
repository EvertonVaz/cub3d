/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:00:15 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/14 07:34:43 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../.libs/MLX42/include/MLX42/MLX42.h"
# include <stdint.h>

typedef struct s_player
{
	double		x;
	double		y;
	int			direction;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
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
	int			check_player;
}				t_checker;

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_mlx;

typedef struct s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
}				t_ray;

typedef struct s_textures
{
	mlx_texture_t	*e_tex;
	mlx_texture_t	*w_tex;
	mlx_texture_t	*s_tex;
	mlx_texture_t	*n_tex;

}					t_textures;

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
	t_mlx		*mlx;
	t_checker	*checker;
	t_player	*player;
	t_ray		*ray;
	t_textures	*texture;
}				t_cub;

typedef struct s_texture_map
{
	char		*identifier;
	char		**texture;
	int			*check;
}				t_texture_map;

#endif