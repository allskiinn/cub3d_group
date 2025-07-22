/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 11:54:57 by asobrinh          #+#    #+#             */
/*   Updated: 2025/06/10 02:23:11 by aliberal         ###   ########.fr       */
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

static int	check_color(int color[3])
{
	int	i;

	i = -1;
	while (++i < 3)
		if (color[i] == -1)
			return (-1);
	return (0);
}

void	check_text_color_error(t_cub *cub)
{
	if (check_color(cub->f_color) || check_color(cub->c_color)
		|| cub->no == NULL || cub->so == NULL || cub->we == NULL
		|| cub->ea == NULL)
	{
		if (check_color(cub->f_color) || check_color(cub->c_color))
			cub->error = 10;
		else
		{
			if (cub->no == NULL || cub->so == NULL || cub->we == NULL
				|| cub->ea == NULL)
				cub->error = 1;
			else
				cub->error = 11;
		}
	}
}
