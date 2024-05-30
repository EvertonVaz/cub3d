/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:11:11 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/30 15:50:28 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_args_return_path_map(int argc, char **argv, t_map **map)
{
	char	*path_map;

	if (argc != 2)
	{
		printf("You need 1 and only 1 file with instructions\n");
		exit(1);
	}
	path_map = ft_strnstr(argv[1],".cub", ft_strlen(argv[1]));
	if (path_map && !ft_strchr(argv[1], '/'))
		path_map = ft_strjoin("./assets/maps/", argv[1], 0);
	else
		path_map = ft_strdup(argv[1]);
	*map = init_data();
	(*map)->path_map = path_map;
}
