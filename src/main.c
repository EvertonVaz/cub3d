/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:13:45 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/14 11:04:18 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_img_size(mlx_texture_t *img)
{
	if (!img)
		handle_error("Error\nSomething went wrong while loading images\n", 0);
	if (img->width != 64 || img->height != 64)
		handle_error("Error\nPlease provide a image with size 64x64 :)\n", 0);
}

void	open_texture(t_cub *cub)
{
	cub->texture->e_tex = mlx_load_png(cub->ea_texture);
	cub->texture->s_tex = mlx_load_png(cub->so_texture);
	cub->texture->n_tex = mlx_load_png(cub->no_texture);
	cub->texture->w_tex = mlx_load_png(cub->we_texture);
	check_img_size(cub->texture->e_tex);
	check_img_size(cub->texture->s_tex);
	check_img_size(cub->texture->n_tex);
	check_img_size(cub->texture->w_tex);
}

t_cub	*get_map_infos(int argc, char **argv)
{
	t_cub	*cub;
	int		fd;

	cub = check_args_init_data(argc, argv);
	fd = open(cub->path_map, O_RDONLY);
	handle_error(NULL, fd);
	cub = fill_map_infos(fd, cub);
	handle_error(check_duplicates(cub), 0);
	check_walls(cub);
	open_texture(cub);
	close(fd);
	return (cub);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = get_map_infos(argc, argv);
	cub->mlx->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	cub->mlx->img = mlx_new_image(cub->mlx->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub->mlx->mlx, cub->mlx->img, 0, 0);
	mlx_set_icon(cub->mlx->mlx, cub->texture->e_tex);
	render(cub);
	mlx_key_hook(cub->mlx->mlx, player_walk, cub);
	mlx_cursor_hook(cub->mlx->mlx, mouse_move, cub);
	mlx_loop(cub->mlx->mlx);
	mlx_terminate(cub->mlx->mlx);
	free_maps(&cub);
	return (0);
}
