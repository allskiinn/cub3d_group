/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:59:07 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/04 17:29:14 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int		ft_cub(char *str, t_cub *cub)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			ft_error(cub, "Invalid map name\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing(str, cub);
	else
		ft_error(cub, "Invalid map name\n");
	return (0);
}

void	ft_initialisation(t_cub *cub)
{
	cub->rx = 0;
	cub->ry = 0;
	
	cub->textures.NO = NULL;
	cub->textures.SO = NULL;
	cub->textures.WE = NULL;
	cub->textures.EA = NULL;
    
    cub->f_color[0] = -1;
	cub->f_color[1] = -1;
	cub->f_color[2] = -1;
    cub->c_color[0] = -1;
	cub->c_color[1] = -1;
	cub->c_color[2] = -1;
    cub->sum = 0;
    cub->checkColor = 0;
    
    cub->map.grid = NULL;
    cub->map.width = 0;
    cub->map.height = 0;
    cub->map.emptyline = 0;
	cub->map.insidemap = 0;
	cub->map.count = 0;
	cub->map.wrongcharmap = 0;
	cub->error = 0;

    cub->player.x = -1;
    cub->player.y = -1;
    cub->player.dir = 'x';
    cub->player.multiplayer = 0;
	
}
