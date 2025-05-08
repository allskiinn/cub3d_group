/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:57:29 by asobrinh          #+#    #+#             */
/*   Updated: 2025/05/08 02:32:38 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int		ft_check_player_around(t_cub *cub)
{
	int px = cub->player.x;
	int py = cub->player.y;

	if (px > 0 && ft_space(cub, px - 1, py)) 
		return (1);
	if (px < cub->map.height - 1 && ft_space(cub, px + 1, py)) 
		return (1);
	if (py > 0 && ft_space(cub, px, py - 1))
		return (1);
	if (py < cub->map.width - 1 && ft_space(cub, px, py + 1))
		return (1);

	return (0);
}

int		ft_space(t_cub *cub, int x, int y)
{
	return (x >= 0 && x < cub->map.height && y >= 0 && y < cub->map.width && cub->map.grid[x][y] == ' ');
}

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

int ft_verify_extention(char *t)
{
	int i;

	i = ft_strlen(t) - 1;
	while (i >= 0 && t[i] != '.')
		i--;
	if (i >= 0 && t[i] == '.')
	{
		if (i + 1 <= ft_strlen(t) && ('x' != ft_tolower(t[i + 1])))
			return (1);
		if (i + 2 <= ft_strlen(t) && ('p' != ft_tolower(t[i + 2])))
			return (1);
		if (i + 3 <= ft_strlen(t) && ('m' != ft_tolower(t[i + 3])))
			return (1);
	}
	else
		return (1);
	return (0);
}

int ft_verify_ext_dir(char *dir)
{
	int fd;

	if ((fd = open(dir, O_RDONLY)) == -1)
		return (1);
	close(fd);
	return (0);
}

int ft_verify_textures(t_cub *cub)
{
    if (ft_verify_extention(cub->textures.NO))
		return (ret(cub, "Error: Extensao da textura NO e invalida.\n"));
	else
		if (ft_verify_ext_dir(cub->textures.NO))
			return (ret(cub, "Error: Textura NO nao existe no caminho referido.\n"));
	if (ft_verify_extention(cub->textures.SO))
		return (ret(cub, "Error: Extensao da textura SO e invalida.\n"));
	else
		if (ft_verify_ext_dir(cub->textures.SO))
			return (ret(cub, "Error: Textura SO nao existe no caminho referido.\n"));
	if (ft_verify_extention(cub->textures.WE))
		return (ret(cub, "Error: Extensao da textura WE e invalida.\n"));
	else
		if (ft_verify_ext_dir(cub->textures.WE))
			return (ret(cub, "Error: Textura WE nao existe no caminho referido.\n"));
	if (ft_verify_extention(cub->textures.EA))
		return (ret(cub, "Error: Extensao da textura EA e invalida.\n"));
	else
		if (ft_verify_ext_dir(cub->textures.EA))
			return (ret(cub, "Error: Textura EA nao existe no caminho referido.\n"));
	return (0);
}
