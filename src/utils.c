/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:13:20 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/13 14:09:59 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	destroy_texture(t_cub *cub)
{
	if (cub && cub->texture->n_tex)
		mlx_delete_texture(cub->texture->n_tex);
	if (cub && cub->texture->s_tex)
		mlx_delete_texture(cub->texture->s_tex);
	if (cub && cub->texture->w_tex)
		mlx_delete_texture(cub->texture->w_tex);
	if (cub && cub->texture->e_tex)
		mlx_delete_texture(cub->texture->e_tex);
}

void	free_maps(t_cub **cub)
{
	if (cub && (*cub)->path_map)
		free((*cub)->path_map);
	if (cub && (*cub)->ea_texture)
		free((*cub)->ea_texture);
	if (cub && (*cub)->we_texture)
		free((*cub)->we_texture);
	if (cub && (*cub)->no_texture)
		free((*cub)->no_texture);
	if (cub && (*cub)->so_texture)
		free((*cub)->so_texture);
	if (cub && (*cub)->map)
		free_split((*cub)->map);
	if (cub && (*cub)->checker)
		free((*cub)->checker);
	if (cub && (*cub)->player)
		free((*cub)->player);
	if (cub && (*cub)->mlx)
		free((*cub)->mlx);
	if (cub && (*cub)->ray)
		free((*cub)->ray);
	destroy_texture((*cub));
	if (cub && (*cub)->texture)
		free((*cub)->texture);
	if (cub && *cub)
		free(*cub);
}

int	handle_error(char *msg, int num)
{
	t_cub	*cub;

	cub = get_address(NULL);
	if (num == -1)
	{
		free_maps(&cub);
		msg = ft_strjoin("Error\n", strerror(errno), 0);
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
		free(msg);
		exit(1);
	}
	if (msg)
	{
		free_maps(&cub);
		write(2, msg, ft_strlen(msg));
		exit(1);
	}
	return (num);
}
