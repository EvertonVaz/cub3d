/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:56:48 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/13 15:47:44 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*check_duplicates(t_cub *cub)
{
	if (cub->checker->check_ea != 1)
		return ("Error\nCheck East texture\n");
	if (cub->checker->check_no != 1)
		return ("Error\nCheck North texture\n");
	if (cub->checker->check_so != 1)
		return ("Error\nCheck South texture\n");
	if (cub->checker->check_we != 1)
		return ("Error\nCheck West texture\n");
	if (cub->checker->check_floor != 1)
		return ("Error\nCheck Floor color\n");
	if (cub->checker->check_ceiling != 1)
		return ("Error\nCheck Ceiling color\n");
	if (cub->checker->check_player != 1)
		return ("Error\nCheck player: You need 1 and only 1 player\n");
	if (cub->checker->check_infos)
		return ("Error\nInvalid map\n");
	return (NULL);
}
