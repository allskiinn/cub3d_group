/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color_resolution.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:01:33 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/10 01:02:35 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int rgb_to_int(int r, int g, int b)
{
    return (r << 16) | (g << 8) | b;
}

void	ft_color_resolution(char **str, t_cub *cub)
{
    cub->i = 1;
	if (cub->map.width > 0 && (cub->NO == NULL || cub->SO == NULL ||
				cub->WE == NULL || cub->EA == NULL))
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
	{
        ft_atoi3(*str, cub, 'F');
		cub->f = rgb_to_int(cub->f_color[0], cub->f_color[1], cub->f_color[2]);
	}
	else if (*str && *str[0] == 'C')
	{
        ft_atoi3(*str, cub, 'C');
		cub->c = rgb_to_int(cub->c_color[0], cub->c_color[1], cub->c_color[2]);
	}
}