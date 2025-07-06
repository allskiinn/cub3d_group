/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:43:58 by aliberal          #+#    #+#             */
/*   Updated: 2025/07/02 17:28:28 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

static int	ft_start(char c, t_cub *cub, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (cub->player.dir != 'x')
			cub->player.multiplayer = 1;
		cub->player.dir = c;
		cub->player.x = j;
		cub->player.y = i;
		return (1);
	}
	return (0);
}

int	ft_copy_map(char *str, t_cub *cub)
{
	static int	i = 0;
	int			j;

	j = 0;
	cub->map.grid[i] = malloc(sizeof(char) * cub->map.width + 1);
	if (!(cub->map.grid[i]))
		return (0);
	while (str[j] != '\0')
	{
		if (ft_start(str[j], cub, i, j) == 1)
			cub->map.grid[i][j] = '0';
		else if (str[j] == ' ')
			cub->map.grid[i][j] = ' ';
		else
			cub->map.grid[i][j] = str[j];
		j++;
	}
	while (j <= (cub->map.width - 1))
	{
		cub->map.grid[i][j] = ' ';
		j++;
	}
	cub->map.grid[i][j] = '\0';
	i++;
	return (0);
}

int	ft_is_map(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_charinstr(str, '1') == 1 || ft_charinstr(str, '0') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1'
				&& str[i] != 'N' && str[i] != 'S'
				&& str[i] != 'E' && str[i] != 'W' && str[i] != '\n'
				&& str[i] != '\t')
			{
				if (cub->map.insidemap == 1)
					cub->map.wrongcharmap = 2;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_map(char *str, t_cub *cub)
{
	static int	nblines = 0;
	static int	sizeline = 0;

	if (ft_is_map(str, cub) == 1)
	{
		check_text_color_error(cub);
		if (ft_strlen(str) > sizeline)
		{
			sizeline = ft_strlen(str);
		}
		nblines = nblines + 1;
	}
	cub->map.height = nblines;
	cub->map.width = sizeline;
}
