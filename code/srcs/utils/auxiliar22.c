/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar22.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 11:54:57 by asobrinh          #+#    #+#             */
/*   Updated: 2025/06/07 11:55:19 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	ft_check_right_col(t_cub *cub)
{
	int	i;
	int	ret;

	i = 1;
	while (i < cub->map.height - 1)
	{
		if (cub->map.grid[i][cub->map.width - 1] == '0')
			return (10);
		if (cub->map.grid[i][cub->map.width - 1] == cub->player.dir)
			return (11);
		if (ft_space(cub, i, cub->map.width - 1))
		{
			ret = ft_check_left_col_spaces(cub, i);
			if (ret != 0)
				return (ret);
		}
		i++;
	}
	return (0);
}

int	ft_check_surroundings(t_cub *cub, int i, int j)
{
	if (i > 0 && ft_space(cub, i - 1, j))
		return (13);
	if (i < cub->map.height - 1 && ft_space(cub, i + 1, j))
		return (14);
	if (j > 0 && ft_space(cub, i, j - 1))
		return (15);
	if (j < cub->map.width - 1 && ft_space(cub, i, j + 1))
		return (16);
	return (0);
}

int	ft_check_map_holes(t_cub *cub)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (i < cub->map.height)
	{
		j = 0;
		while (j < cub->map.width)
		{
			if (cub->map.grid[i][j] == '0'
				|| cub->map.grid[i][j] == cub->player.dir)
			{
				ret = ft_check_surroundings(cub, i, j);
				if (ret != 0)
					return (ret);
			}
			j++;
		}
		i++;
	}
	return (0);
}
