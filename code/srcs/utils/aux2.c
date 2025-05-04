/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:34:43 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/04 20:00:25 by aliberal         ###   ########.fr       */
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
			return (1);
		i++;
	}
	return (0);
}

int		ft_walls(t_cub *cub)
{
	int i;

	i = 0;
	while (i < cub->map.height)
	{
		if (cub->map.grid[i][0] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < cub->map.height)
	{
		if (cub->map.grid[i][cub->map.width - 1] != '1')
			return (1);
		i++;
	}
	if (ft_walls_util(cub->map.grid[0]) == 1)
		return (1);
	if (ft_walls_util(cub->map.grid[cub->map.height - 1]) == 1)
		return (1);
	return (0);
}
