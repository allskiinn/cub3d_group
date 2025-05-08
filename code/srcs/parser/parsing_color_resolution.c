/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color_resolution.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:01:33 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/08 01:12:17 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void	ft_color_resolution(char **str, t_cub *cub)
{
    cub->i = 1;
	if (cub->map.width > 0 && (cub->textures.NO == NULL || cub->textures.SO == NULL ||
				cub->textures.WE == NULL || cub->textures.EA == NULL))
		cub->error = 1;
	if (*str && *str[0] == 'R')
	{
		if (cub->rx != 0 && cub->ry != 0)
			cub->error = 6;
		cub->rx = ft_atoi2(*str, cub);
		cub->ry = ft_atoi2(*str, cub);
		if (ft_atoi2(*str, cub) > 0 || cub->rx == 0 || cub->ry == 0)
			cub->error = 7;
	}
	else if (*str && *str[0] == 'F')
        ft_atoi3(*str, cub, 'F');
	else if (*str && *str[0] == 'C')
        ft_atoi3(*str, cub, 'C');
}