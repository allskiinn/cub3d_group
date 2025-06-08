/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:35:04 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/11 00:09:34 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int ret(t_cub *cub,char *str)
{
	ft_error(cub, str);
	return (1);
}

int ft_verify_errors(t_cub *cub)
{
	int	error;
	
	error = ft_walls(cub);
	if (error != 0)
	{
		border_map_errors(cub, error);
		return (1);
	}
	if (cub->player.dir == 'x')
		return (ret(cub, "Error\nNo player found in the map.\n"));
	if (cub->checkColor != 6)
		return (ret(cub, "Error\nBad floor or ceiling color data.\n"));
	if (cub->player.multiplayer == 1)
		return (ret(cub, "Error\nMore than one player starting.\n"));
	if (cub->map.emptyline == 1)
		return (ret(cub, "Error\nEmpty line found inside map.\n"));
	if (cub->map.wrongcharmap == 2)
		return (ret(cub, "Error\nInvalid characters found in the map.\n"));
	if (ft_checkPlayer(cub) == 1)
		return (ret(cub, "Error\nInvalid characters around player.\n"));
	if (ft_check_player_around(cub) == 1)
		return (ret(cub, "Error\nSpace found adjacent player start.\n"));
	if (ft_verify_textures(cub))
		return (1);
	return (0);
}

void	ft_error(t_cub *cub, char *str)
{
	int	i;

	i = -1;
	write(1, str, ft_strlen(str));
	if (cub->NO)
		free(cub->NO);
	if (cub->SO)
		free(cub->SO);
	if (cub->WE)
		free(cub->WE);
	if (cub->EA)
		free(cub->EA);
	if (cub->map.grid)
	{
		while (++i < cub->map.height)
			free(cub->map.grid[i]);
	}
	ft_exit(cub);
}

int		ft_exit(t_cub *cub)
{
	if (cub->img.img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
	if (cub->textures[0].img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->textures[0].img_ptr);
	if (cub->textures[1].img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->textures[1].img_ptr);
	if (cub->textures[2].img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->textures[2].img_ptr);
	if (cub->textures[3].img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->textures[3].img_ptr);
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx_ptr, cub->mlx_win);
	exit(0);
}
