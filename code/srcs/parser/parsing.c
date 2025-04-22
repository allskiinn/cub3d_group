/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:23:21 by aliberal          #+#    #+#             */
/*   Updated: 2025/04/23 00:33:39 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int		ft_parsing_map(char *file, t_map *map)
{
	int			fd;
	int			ret;
	char		*str;

	ret = 1;
	str = NULL;
	fd = open(file, O_RDONLY);
	if (!(map->map = malloc(sizeof(char*) * map->nblines)))
		return (0);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, map);
		if (map->insidemap == 1 && ft_lignevide(str) == 0 &&
				map->count < map->nblines)
			map->lignevide = 1;
		if ((map->insidemap = ft_is_map(str, map)) == 1)
		{
			map->count++;
			ft_copy_map(str, map);
		}
		free(str);
	}
	close(fd);
	return (0);
}

void	ft_parsing(char *file, t_map *map)
{
	int			fd;
	int			ret;
	char		*str;

	ret = 1;
	str = NULL;
	if ((fd = open(file, O_DIRECTORY)) != -1)
		ft_error(map, "Invalide : is a directory\n");
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error(map, "file .cub invalide\n");
	map->error = 0;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, map);
		if (map->error == 2)
			ft_error(map, "La partie parsing detecte une erreur\n");
		ft_color_resolution(&str, map);
		ft_texture(str, map);
		ft_map(str, map);
		free(str);
	}
	close(fd);
	if (map->map_height == 0 || map->map_width == 0)
		ft_error(map, "Map absente\n");
	ft_parsing_map(file, map);
}