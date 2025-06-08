/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:35:04 by aliberal          #+#    #+#             */
/*   Updated: 2025/06/06 15:10:00 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	ret(t_cub *cub, char *str)
{
	ft_error(cub, str);
	return (1);
}

static int	ft_verify_map_content(t_cub *cub)
{
	if (cub->map.wrongcharmap == 2)
		return (ret(cub, "Error\nInvalid map chars.\n"));
	if (ft_checkplayer(cub) == 1)
		return (ret(cub, "Error\nInvalid chars near player.\n"));
	if (ft_check_player_around(cub) == 1)
		return (ret(cub, "Error\nSpace near player.\n"));
	if (ft_verify_textures(cub))
		return (1);
	return (0);
}

int	ft_verify_errors(t_cub *cub)
{
	int	error;

	error = ft_walls(cub);
	if (error != 0)
	{
		border_map_errors(cub, error);
		return (1);
	}
	if (cub->player.dir == 'x')
		return (ret(cub, "Error\nno player in map.\n"));
	if (cub->checkcolor != 6)
		return (ret(cub, "Error\nBad color data.\n"));
	if (cub->player.multiplayer == 1)
		return (ret(cub, "Error\nMultiple players.\n"));
	if (cub->map.emptyline == 1)
		return (ret(cub, "Error\nEmpty line in map.\n"));
	return (ft_verify_map_content(cub));
}

void	ft_error(t_cub *cub, char *str)
{
	int	i;

	write(1, str, ft_strlen(str));
	if (cub->no)
		free(cub->no);
	if (cub->so)
		free(cub->so);
	if (cub->we)
		free(cub->we);
	if (cub->ea)
		free(cub->ea);
	if (cub->map.grid)
	{
		i = 0;
		while (i < cub->map.height)
			free(cub->map.grid[i++]);
		free(cub->map.grid);
	}
	ft_exit(cub);
}

int	ft_exit(t_cub *cub)
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
		(mlx_destroy_window(cub->mlx_ptr, cub->mlx_win));
	if (cub->mlx_ptr)
		mlx_destroy_display(cub->mlx_ptr);
	free(cub->mlx_ptr);
	exit(0);
}
