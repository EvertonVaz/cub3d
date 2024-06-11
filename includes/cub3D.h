/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:29:31 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/11 10:02:00 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "structs.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 800
# define TILE_SIZE 8
# define SPEED 0.1

t_cub	*check_args_init_data(int argc, char **argv);
t_cub	*get_map_address(t_cub *cub);
t_cub	*fill_map_infos(int fd, t_cub *cub);
int32_t	get_colors(t_cub **cub, char *line, char identifier);
int		handle_texture(t_cub **cub, char *line);
char	*check_duplicates(t_cub *cub);
void	free_maps(t_cub **cub);
int		handle_error(char *msg, int num);
t_cub	*init_data(void);
int		check_color(char **colors);
int32_t	save_colors(char **colors, t_cub **cub, char identifier);
void	check_walls(t_cub *cub);
void	get_player_posicion(t_cub *cub, int x, int y);
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	draw_map(void *param);
void	player_walk(mlx_key_data_t key, void *param);
void	raycasting(t_cub *cub);
int		hit(t_cub *cub);
void	paint_background(t_cub *cub);

#endif