/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:34:43 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/06 04:25:21 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int		ft_nb_comma(const char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			j++;
	}
	return (j);
}

int		ft_strlen2(char *str)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

int		ft_walls_util(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
		{
			if (str[i] == ' ')
			{
				while (i <= (ft_strlen(str)) && str[i] == ' ')
					i++;
				if (i != (ft_strlen(str)) && str[i] != '1')
					return (1);
			}
			else
			{
				if (str[i] == '0')
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int		ft_checkPlayer(t_cub *cub)
{
	int x;
	int y;

	x = cub->player.x;
	y = cub->player.y;
	if (cub->map.grid[x - 1][y] != '1' && cub->map.grid[x - 1][y] != '0')
		return (1);
	if (cub->map.grid[x + 1][y] != '1' && cub->map.grid[x + 1][y] != '0')
		return (1);
	if (cub->map.grid[x][y - 1] != '1' && cub->map.grid[x][y - 1] != '0')
		return (1);
	if (cub->map.grid[x][y + 1] != '1' && cub->map.grid[x][y + 1] != '0')
		return (1);
	return (0);
}

int		ft_walls(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (i < cub->map.width)
	{
		if (cub->map.grid[0][i] == '0')
			return (1);
		if (cub->map.grid[0][i] == cub->player.dir)
			return (2);
		i++;
	}

	i = 0;
	while (i < cub->map.width)
	{
		if (cub->map.grid[cub->map.height - 1][i] == '0')
			return (4);
		if (cub->map.grid[cub->map.height - 1][i] == cub->player.dir)
			return (5);
		i++;
	}

	i = 1;
	while (i < cub->map.height - 1)
	{
		if (cub->map.grid[i][0] == '0')
			return (7);
		if (cub->map.grid[i][0] == cub->player.dir)
			return (8);
		if (ft_space(cub, i, 0))
		{
			j = 0;
			while (j < cub->map.width && ft_space(cub, i, j))
				j++;
			if (j == cub->map.width || cub->map.grid[i][j] != '1')
				return (9);
		}
		i++;
	}

	i = 1;
	while (i < cub->map.height - 1)
	{
		if (cub->map.grid[i][cub->map.width - 1] == '0')
			return (10);
		if (cub->map.grid[i][cub->map.width - 1] == cub->player.dir)
			return (11);
		if (ft_space(cub, i, cub->map.width - 1))
		{
			j = cub->map.width - 1;
			while (j >= 0 && ft_space(cub, i, j))
				j--;
			if (j == -1 || cub->map.grid[i][j] != '1')
				return (12);
		}
		i++;
	}

	i = 0;
	while (i < cub->map.height)
	{
		j = 0;
		while (j < cub->map.width)
		{
			if (cub->map.grid[i][j] == '0' || cub->map.grid[i][j] == cub->player.dir)
			{
				if (i > 0 && ft_space(cub, i - 1, j))
					return (13);
				if (i < cub->map.height - 1 && ft_space(cub, i + 1, j))
					return (14);
				if (j > 0 && ft_space(cub, i, j - 1))
					return (15);
				if (j < cub->map.width - 1 && ft_space(cub, i, j + 1))
					return (16);
			}
			j++;
		}
		i++;
	}

	return (0);
}
