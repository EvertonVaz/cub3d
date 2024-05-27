/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:11:26 by egeraldo          #+#    #+#             */
/*   Updated: 2024/05/27 18:11:54 by etovaz           ###   ########.fr       */
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

t_map	*init_data(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->we_texture = NULL;
	map->so_texture = NULL;
	map->no_texture = NULL;
	map->ea_texture = NULL;
	map->map = NULL;
	map->ceiling_color = -1;
	map->floor_color = -1;
	return (map);
}

t_map	*get_map_address(t_map *map)
{
	static t_map	*map_address;

	if (!map_address)
		map_address = map;
	return (map_address);
}

char	**handle_map(char *line, int fd)
{
	char	**map;
	char	*trim;
	int		i;

	trim = ft_strtrim(line, " ");
	if (trim && (trim[0] == '1' || trim[0] == '0'))
	{
		map = malloc(sizeof(char *) * 64);
		i = 0;
		while (1)
		{
			line[ft_strlen(line) - 1] = '\0';
			map[i] = ft_strdup(line);
			i++;
			free(line);
			line = get_next_line(fd);
			map[i] = NULL;
			if (!line)
				break ;
		}
		free(trim);
		return (map);
	}
	free(trim);
	return (NULL);
}

t_map	*fill_map_infos(int fd)
{
	t_map	*map;
	char	*line;

	map = init_data();
	while (1)
	{
		line = get_next_line(fd);
		if (fill_texture(&map, line))
			;
		else if (ft_strchr(line, 'C'))
			map->ceiling_color = get_colors(line);
		else if (ft_strchr(line, 'F'))
			map->floor_color = get_colors(line);
		else
			map->map = handle_map(line, fd);
		if (map->map)
			return (map);
		free(line);
	}
	return (NULL);
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