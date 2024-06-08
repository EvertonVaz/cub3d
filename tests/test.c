/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:54:28 by etovaz            #+#    #+#             */
/*   Updated: 2024/05/30 13:49:11 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit/minunit.h"
#include "../includes/cub3D.h"

MU_TEST(test_fill_map_infos) {
    int fd = open("example.cub", O_RDONLY); // Substitua "test_map.txt" pelo nome do seu arquivo de teste
    t_map *result = fill_map_infos(fd);
    // Substitua "expected_result" pelo resultado esperado
    // Você pode querer verificar vários campos em "result", não apenas se é NULL
    mu_assert(result != NULL, "Error: fill_map_infos returned NULL");
    close(fd);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_fill_map_infos);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return minunit_status;
}