/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:23:21 by aliberal          #+#    #+#             */
/*   Updated: 2025/07/28 05:03:29 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

static int	ft_parse_map_lines(int fd, t_cub *cub)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		if (cub->map.insidemap == 1 && ft_emptyline(str) == 0
			&& cub->map.count < cub->map.height)
			cub->map.emptyline = 1;
		cub->map.insidemap = ft_is_map(str, cub);
		if (cub->map.insidemap == 1)
		{
			cub->map.count++;
			ft_copy_map(str, cub);
		}
		free(str);
		str = get_next_line(fd);
	}
	return (0);
}

static int	ft_parsing_map(char *file, t_cub *cub)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_error(cub, "Error opening map file for second pass\n");
		return (1);
	}
	cub->map.grid = malloc(sizeof(char *) * cub->map.height);
	if (!(cub->map.grid))
	{
		close(fd);
		return (1);
	}
	if (ft_parse_map_lines(fd, cub) == 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

static int	ft_main_parsing_loop(int fd, t_cub *cub)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		ft_color(&str, cub);
		ft_texture(str, cub);
		ft_map(str, cub);
		free(str);
		str = get_next_line(fd);
	}
	if (cub->error)
	{
		items_map_errors(cub, cub->error);
		free(str);
		return (1);
	}
	return (0);
}

int	ft_parsing(char *file, t_cub *cub)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_error(cub, "Invalid .cub file\n");
		return (1);
	}
	cub->error = 0;
	if (ft_main_parsing_loop(fd, cub) == 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	if (cub->map.height == 0 || cub->map.width == 0)
	{
		ft_error(cub, "Map absente\n");
		return (1);
	}
	if (ft_parsing_map(file, cub) == 1)
		return (1);
	return (0);
}
