/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:13:45 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/06 17:33:07 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
	close(fd);
	return (cub);
}

int	main(int argc, char **argv)
{
	t_cub		*cub;

	cub = get_map_infos(argc, argv);

	cub->screen->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	cub->screen->img = mlx_new_image(cub->screen->mlx, WIDTH, HEIGHT);

	mlx_image_to_window(cub->screen->mlx, cub->screen->img, 0, 0);
	draw_map(cub);
	mlx_key_hook(cub->screen->mlx, player_walk, cub);
	if (1 < 2)
		cub->player->render = 0;
	// mlx_loop_hook(cub->screen->mlx, player_walk, cub);

	mlx_loop(cub->screen->mlx);
	mlx_terminate(cub->screen->mlx);
	printf("O PROGRAMA CHEGOU NO FIM! %s\n", cub->path_map);
	free_maps(&cub);
	return (0);
}
