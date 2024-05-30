/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:11:11 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/30 15:07:28 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*check_args_return_path_map(int argc, char **argv)
{
	char	*path_map;

	if (argc != 2)
		return (ft_strdup(""));
	path_map = ft_strnstr(argv[1],".cub", ft_strlen(argv[1]));
	if (path_map && !ft_strchr(argv[1], '/'))
		path_map = ft_strjoin("./assets/maps/", argv[1], 0);
	else
		path_map = ft_strdup(argv[1]);
	return (path_map);
}
