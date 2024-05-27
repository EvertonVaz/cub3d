/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:13:45 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/27 12:17:45 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	handle_error(char *msg, int num)
{
	if (num < 0)
		exit(write(2, msg, ft_strlen(msg)));
	return (num);
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = check_args_return_fd(argc, argv);
	handle_error("Error: Invalid arguments\n", fd);
	fill_map_infos(fd);
	printf("%d\n", check_args_return_fd(argc, argv));

	return (0);
}