## Já implementado

valgrind --leak-check=full ./cub3D
valgrind --leak-check=full ./cub3D faltando_cor.cub faltando_path_we.cub
valgrind --leak-check=full ./cub3D oi
valgrind --leak-check=full ./cub3D ./assets/maps/invalid/faltando_path_we.cub
valgrind --leak-check=full ./cub3D ./assets/maps/invalid/faltando_cor.cub
valgrind --leak-check=full ./cub3D ./assets/maps/invalid/cor_acima_do_range.cub
valgrind --leak-check=full ./cub3D ./assets/maps/invalid/cor_abaixo_do_range.cub
valgrind --leak-check=full ./cub3D ./assets/maps/invalid/arquivo_vazio.cub
valgrind --leak-check=full ./cub3D ./assets/maps/invalid/arquivo_sem_permissao.cub
valgrind --leak-check=full ./cub3D ./assets/maps/invalid/path_invalido.cub
valgrind --leak-check=full ./cub3D ./assets/maps/invalid/path_sem_permissão.cub
valgrind --leak-check=full ./cub3D ./assets/maps/invalid/invalid_map1.cub
valgrind --leak-check=full ./cub3D ./assets/maps/invalid/invalid_map2.cub
valgrind --leak-check=full ./cub3D ./assets/maps/invalid/invalid_map3.cub



if (ray->side == 0) // Lado vertical (Leste/Oeste)
		{
			if (ray->dir_x > 0)
				mlx_image_to_window(cub->mlx->mlx, cub->sprites->e_tex1, x, ray->draw_start); // Leste (Amarelo)
			else
				mlx_image_to_window(cub->mlx->mlx, cub->sprites->w_tex1, x, ray->draw_start); // Oeste (Vermelho)
		}
		else // Lado horizontal (Norte/Sul)
		{
			if (ray->dir_y > ray->draw_start)
				mlx_image_to_window(cub->mlx->mlx, cub->sprites->s_tex1, x, ray->draw_start); // Sul (Preto)
			else
				mlx_image_to_window(cub->mlx->mlx, cub->sprites->n_tex1, x, ray->draw_start); // Norte (Azul)
		}

void	load(t_cub **cub)
{
	(*cub)->sprites = malloc(sizeof(t_sprites));
	(*cub)->sprites->e_tex = mlx_load_png((*cub)->ea_texture);
	(*cub)->sprites->e_tex1 = mlx_texture_to_image((*cub)->mlx,
			(*cub)->sprites->e_tex);
	(*cub)->sprites->w_tex = mlx_load_png((*cub)->we_texture);
	(*cub)->sprites->w_tex1 = mlx_texture_to_image((*cub)->mlx,
			(*cub)->sprites->w_tex);
	(*cub)->sprites->s_tex = mlx_load_png((*cub)->so_texture);
	(*cub)->sprites->s_tex1 = mlx_texture_to_image((*cub)->mlx,
			(*cub)->sprites->s_tex);
	(*cub)->sprites->n_tex = mlx_load_png((*cub)->no_texture);
	(*cub)->sprites->n_tex1 = mlx_texture_to_image((*cub)->mlx,
			(*cub)->sprites->n_tex);
}

