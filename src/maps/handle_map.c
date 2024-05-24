/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:11:26 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/24 17:40:15 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
	os argumentos podem estar em qualquer ordem e podem ter espaços
	checar as cores, de 0 a 255
	se certificar que o mapa e a ultima instrução do arquivo
	as coordenadas das texturas devem ser válidas
	validar se existe um player no mapa
	verificar se o mapa esta completamente fechado por paredes
 */

t_map	*get_map_address(t_map *map)
{
	t_map	*map_address;

	if (!map_address)
		map_address = map;
	return (map_address);
}

int	check_color(char *color)
{
	int	n;
	if (!color)
		return (-1);
	n = ft_atoi(color);
	return (n >= 0 && n <= 255);
}

int32_t	get_colors(char *line)
{
	char	**colors;
	int32_t	color;
	int		check;

	color = 0;
	colors = ft_split(line, ' ');
	if (check_color(colors[1]) && check_color(colors[2]) && check_color(colors[3]))
	{
		color = ft_pixel(ft_atoi(colors[1]), ft_atoi(colors[2]), ft_atoi(colors[3]), 255);
		free_split(colors);
		return (color);
	}
	free_split(colors);
	return (-1);
}

int	validate_infos(t_map *map)
{
	if (map->ceiling_color < 0 || map->floor_color < 0)
		return (0);
	return (1);
}

t_map	*fill_map_infos(int fd)
{
	t_map	*map;
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		fill_texture(&map, line);
		if (ft_strchr(line, 'C'))
			map->ceiling_color = get_colors(line);
		else if (ft_strchr(line, 'F'))
			map->floor_color = get_colors(line);
		// else
		// 	get_map(line);
		free(line);
	}
	if (!map->map)
		return (NULL);
	return (map);
}

/*
O mapa deve ser composto de apenas 6 caracteres possíveis:
0 para um espaço vazio,
1 para uma parede,
e N, S, E ou W para a posição inicial do jogador
e orientação de spawn.
*/

/*
O mapa deve estar fechado/rodeado por paredes,
	se não o programa deve retornar um erro.

Exceto pelo conteúdo do mapa,
	cada tipo de elemento pode ser separado por uma ou mais linha(s)
	vazia(s).

Exceto pelo conteúdo do mapa que sempre deve ser o último,
	cada tipo de elemento pode ser definido em qualquer ordem
	no arquivo.

Exceto pelo mapa,
	cada tipo de informação de um elemento pode ser separado
	por um ou mais espaço(s).

O mapa deve ser analisado como está no arquivo.
Espaços são uma parte válida do mapa e cabe a você lidar com isso.
Você deve ser capaz de analisar qualquer tipo de mapa,
desde que respeite as regras do mapa.

Cada elemento (exceto o mapa) tem como primeira informação
o identificador do tipo (composto por um ou dois caracteres),
seguido por todas as informações específicas para cada objeto
em uma ordem estrita, 	como:
 */