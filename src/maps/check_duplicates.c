/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:56:48 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/30 14:11:44 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*check_duplicates(t_map *map)
{
	if (map->checker->check_ea != 1)
		return ("Error\nCheck East texture\n");
	if (map->checker->check_no != 1)
		return ("Error\nCheck North texture\n");
	if (map->checker->check_so != 1)
		return ("Error\nCheck South texture\n");
	if (map->checker->check_we != 1)
		return ("Error\nCheck West texture\n");
	if (map->checker->check_floor != 1)
		return ("Error\nCheck Floor color\n");
	if (map->checker->check_ceiling != 1)
		return ("Error\nCheck Ceiling color\n");
	if (map->checker->check_infos)
		return ("Error\nCheck Map infos\n");
	return (NULL);
}

