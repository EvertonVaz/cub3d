## Já implementado

valgrind --leak-check=full ./cub3D
valgrind --leak-check=full ./cub3D faltando_cor.cub faltando_path_we.cub
valgrind --leak-check=full ./cub3D oi
valgrind --leak-check=full ./cub3D faltando_path_we.cub
valgrind --leak-check=full ./cub3D faltando_cor.cub
valgrind --leak-check=full ./cub3D cor_acima_do_range.cub
valgrind --leak-check=full ./cub3D cor_abaixo_do_range.cub
valgrind --leak-check=full ./cub3D arquivo_vazio.cub
valgrind --leak-check=full ./cub3D arquivo_sem_permissao.cub
valgrind --leak-check=full ./cub3D path_invalido.cub
valgrind --leak-check=full ./cub3D path_sem_permissão.cub