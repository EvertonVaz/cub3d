/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:11:11 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/27 18:19:59 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_args_return_fd(int argc, char **argv)
{
	char	*path_map;
	int		fd;

	if (argc != 2)
		return (-1);
	path_map = ft_strnstr(argv[1],".cub", ft_strlen(argv[1]));
	if (path_map && !ft_strchr(argv[1], '/'))
		path_map = ft_strjoin("./assets/maps/", argv[1], 0);
	else
		path_map = argv[1];
	fd = open(path_map, O_RDONLY);
	if (argv && argv[0] && argv[1] && ft_strncmp(argv[1], path_map, ft_strlen(path_map)) != 0)
		free(path_map);
	return (fd);
}
