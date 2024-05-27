/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:29:31 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/27 12:52:36 by etovaz           ###   ########.fr       */
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

int		check_args_return_fd(int argc, char **argv);
t_map	*fill_map_infos(int fd);
int32_t	get_colors(char *line);
int		fill_texture(t_map **map, char *line);
int		validate_texture_path(t_map map);

#endif