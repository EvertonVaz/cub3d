/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:13:45 by egeraldo          #+#    #+#             */
/*   Updated: 2024/06/10 15:46:50 by egeraldo         ###   ########.fr       */
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
	// check_walls(cub);
	close(fd);
	return (cub);
}

void	paint_background(t_cub *cub)
{
	int	half = HEIGHT / 2;
	int	x;
	int	y;

	y = -1;
	while (++y <= half)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(cub->mlx->img, x, y, ft_pixel(150, 75, 150, 255));
	}
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(cub->mlx->img, x, y, ft_pixel(75, 150, 75, 255));
	}
}

int	main(int argc, char **argv)
{
	t_cub		*cub;

	cub = get_map_infos(argc, argv);
	cub->mlx->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	cub->mlx->img = mlx_new_image(cub->mlx->mlx, WIDTH, HEIGHT);
	paint_background(cub);
	mlx_image_to_window(cub->mlx->mlx, cub->mlx->img, 0, 0);
	draw_map(cub);
	mlx_key_hook(cub->mlx->mlx, player_walk, cub);

	mlx_loop(cub->mlx->mlx);
	mlx_terminate(cub->mlx->mlx);
	printf("O PROGRAMA CHEGOU NO FIM! %s\n", cub->path_map);
	free_maps(&cub);
	return (0);
}
