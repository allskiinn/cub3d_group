/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color_resolution.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:01:33 by aliberal          #+#    #+#             */
/*   Updated: 2025/07/27 08:23:17 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

static int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	ft_color(char **str, t_cub *cub)
{
	cub->i = 1;
	if (cub->map.width > 0 && (cub->no == NULL || cub->so == NULL
			|| cub->we == NULL || cub->ea == NULL))
		cub->error = 1;
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
