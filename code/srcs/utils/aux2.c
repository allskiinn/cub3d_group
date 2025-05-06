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
	while (i < cub->map.height)
	{
		if (cub->map.grid[i][0] != '1')
		{
			j = 0;
			if (cub->map.grid[i][j] == ' ')
			{
				while (j <= (cub->map.width - 1) && (cub->map.grid[i][j] == ' '))
					j++;
				if (cub->map.grid[i][j] != '1')
					return (1);
			}
			else
				return (1);
			
		}
		i++;
	}
	i = 0;
	while (i < cub->map.height)
	{
		if (cub->map.grid[i][cub->map.width - 1] != '1')
		{
			j = cub->map.width - 1;
			if (cub->map.grid[i][j] == ' ')
			{
				while (j != 0 && (cub->map.grid[i][j] == ' '))
					j--;
				if (cub->map.grid[i][j] != '1')
					return (1);
			}
			else
				return (1);
		}
		i++;
	}
	if (ft_walls_util(cub->map.grid[0]) == 1)
		return (1);
	if (ft_walls_util(cub->map.grid[cub->map.height - 1]) == 1)
		return (1);
	return (0);
}
