## Já implementado

valgrind --leak-check=full --suppressions=supress.txt ./cub3D
valgrind --leak-check=full --suppressions=supress.txt ./cub3D faltando_cor.cub faltando_path_we.cub
valgrind --leak-check=full --suppressions=supress.txt ./cub3D oi
valgrind --leak-check=full --suppressions=supress.txt ./cub3D ./assets/maps/invalid/faltando_path_we.cub
valgrind --leak-check=full --suppressions=supress.txt ./cub3D ./assets/maps/invalid/faltando_cor.cub
valgrind --leak-check=full --suppressions=supress.txt ./cub3D ./assets/maps/invalid/cor_acima_do_range.cub
valgrind --leak-check=full --suppressions=supress.txt ./cub3D ./assets/maps/invalid/cor_abaixo_do_range.cub
valgrind --leak-check=full --suppressions=supress.txt ./cub3D ./assets/maps/invalid/arquivo_vazio.cub
valgrind --leak-check=full --suppressions=supress.txt ./cub3D ./assets/maps/invalid/arquivo_sem_permissao.cub
valgrind --leak-check=full --suppressions=supress.txt ./cub3D ./assets/maps/invalid/path_invalido.cub
valgrind --leak-check=full --suppressions=supress.txt ./cub3D ./assets/maps/invalid/path_sem_permissao.cub
valgrind --leak-check=full --suppressions=supress.txt ./cub3D ./assets/maps/invalid/invalid_map1.cub
valgrind --leak-check=full --suppressions=supress.txt ./cub3D ./assets/maps/invalid/invalid_map2.cub
valgrind --leak-check=full --suppressions=supress.txt ./cub3D ./assets/maps/invalid/invalid_map3.cub
