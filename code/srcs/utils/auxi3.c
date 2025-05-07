/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:57:29 by asobrinh          #+#    #+#             */
/*   Updated: 2025/05/07 12:57:31 by asobrinh         ###   ########.fr       */
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

int ft_verify_textures(t_cub *cub)
{
    if (!cub->textures.NO)
        return (ret(cub, "Error: Caminho da textura NO não definido.\n"));
    if (!cub->textures.SO)
        return (ret(cub, "Error: Caminho da textura SO não definido.\n"));
    if (!cub->textures.WE)
        return (ret(cub, "Error: Caminho da textura WE não definido.\n"));
    if (!cub->textures.EA)
        return (ret(cub, "Error: Caminho da textura EA não definido.\n"));
    return (0);
}


