/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:29:31 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/28 15:30:48 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include "structs.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

char	*check_args_return_path_map(int argc, char **argv);
t_map	*get_map_address(t_map *map);
t_map	*fill_map_infos(int fd);
int32_t	get_colors(t_map **map, char *line, char identifier);
char	*handle_texture(t_map **map, char *line);
int		fill_texture(t_map **map, char *side, char *texture);
char	*check_duplicates(t_map *map);
void	free_maps(t_map **map);
int		handle_error(char *msg, int num);

#endif