/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:56:48 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/28 15:29:30 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*check_duplicates(t_map *map)
{
	if (map->check_ea != 1)
		return ("Error\nCheck East texture\n");
	if (map->check_no != 1)
		return ("Error\nCheck North texture\n");
	if (map->check_so != 1)
		return ("Error\nCheck South texture\n");
	if (map->check_we != 1)
		return ("Error\nCheck West texture\n");
	if (map->floor_check != 1)
		return ("Error\nCheck Floor color\n");
	if (map->ceiling_check != 1)
		return ("Error\nCheck Ceiling color\n");
	return (NULL);
}
