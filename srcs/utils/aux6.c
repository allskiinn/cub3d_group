/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 11:41:50 by asobrinh          #+#    #+#             */
/*   Updated: 2025/06/07 11:42:10 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	ft_check_top_row(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->map.width)
	{
		if (cub->map.grid[0][i] == '0')
			return (1);
		if (cub->map.grid[0][i] == cub->player.dir)
			return (2);
		i++;
	}
	return (0);
}

int	ft_check_bottom_row(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->map.width)
	{
		if (cub->map.grid[cub->map.height - 1][i] == '0')
			return (4);
		if (cub->map.grid[cub->map.height - 1][i] == cub->player.dir)
			return (5);
		i++;
	}
	return (0);
}

int	ft_check_left_col_spaces(t_cub *cub, int i)
{
	int	j;

	j = 0;
	while (j < cub->map.width && ft_space(cub, i, j))
		j++;
	if (j == cub->map.width || cub->map.grid[i][j] != '1')
		return (9);
	return (0);
}

int	ft_check_left_col(t_cub *cub)
{
	int	i;
	int	ret;

	i = 1;
	while (i < cub->map.height - 1)
	{
		if (cub->map.grid[i][0] == '0')
			return (7);
		if (cub->map.grid[i][0] == cub->player.dir)
			return (8);
		if (ft_space(cub, i, 0))
		{
			ret = ft_check_left_col_spaces(cub, i);
			if (ret != 0)
				return (ret);
		}
		i++;
	}
	return (0);
}

int	ft_check_right_col_spaces(t_cub *cub, int i)
{
	int	j;

	j = cub->map.width - 1;
	while (j >= 0 && ft_space(cub, i, j))
		j--;
	if (j == -1 || cub->map.grid[i][j] != '1')
		return (12);
	return (0);
}
