/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:29:31 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/05 12:10:46 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "structs.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void	check_args_return_path_map(int argc, char **argv, t_map **map);
t_map	*get_map_address(t_map *map);
t_map	*fill_map_infos(int fd);
int32_t	get_colors(t_map **map, char *line, char identifier);
int		handle_texture(t_map **map, char *line);
char	*check_duplicates(t_map *map);
void	free_maps(t_map **map);
int		handle_error(char *msg, int num);
t_map	*init_data(void);
int		check_color(char **colors);
int32_t	save_colors(char **colors, t_map **map, char identifier);
void	check_walls(t_map *map);
#endif