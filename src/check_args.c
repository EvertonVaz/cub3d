/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:11:11 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/28 10:01:45 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*check_args_return_path_map(int argc, char **argv)
{
	char	*path_map;

	if (argc != 2)
		return (NULL);
	path_map = ft_strnstr(argv[1],".cub", ft_strlen(argv[1]));
	if (path_map && !ft_strchr(argv[1], '/'))
		path_map = ft_strjoin("./assets/maps/", argv[1], 0);
	else
		path_map = argv[1];
	return (path_map);
}
