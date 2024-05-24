/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:29:31 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/24 17:24:47 by egeraldo         ###   ########.fr       */
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
t_map	*get_map(int fd);
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
char	*get_path_texture(char *line, char *direction);
void	fill_texture(t_map **map, char *line);

#endif