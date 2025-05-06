/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:35:04 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/06 04:27:37 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	ft_verify_errors(t_cub *cub)
{
	if (ft_walls(cub) == 1)
	{
		ft_error(cub, "Map not surrounded by 1\n");
		return (1);
	}
	if (cub->player.dir == 'x')
	{
		ft_error(cub, "No player\n");
		return (1);
	}
	if (cub->checkColor != 6)
	{
		ft_error(cub, "Bad F or C data\n");
		return (1);
	}
	if (cub->player.multiplayer == 1)
	{
		ft_error(cub, "More than one player\n");
		return (1);
	}
	if (cub->map.emptyline == 1)
	{
		ft_error(cub, "empty line on the map\n");
		return (1);
	}
	if (cub->map.wrongcharmap == 2)
	{
		ft_error(cub, "Invalid characters on the map\n");
		return (1);
	}
	if (ft_checkPlayer(cub) == 1)
	{
		ft_error(cub, "Invalid characters around the starting point\n");
		return (1);
	}
	return (0);
}

void	ft_error(t_cub *cub, char *str)
{
	int i;

	i = -1;
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	if (cub->textures.NO)
		free(cub->textures.NO);
	if (cub->textures.SO)
		free(cub->textures.SO);
	if (cub->textures.WE)
		free(cub->textures.WE);
	if (cub->textures.EA)
		free(cub->textures.EA);
	if (cub->map.grid)
	{
		while (++i < cub->map.height)
			free(cub->map.grid[i]);
	}
}