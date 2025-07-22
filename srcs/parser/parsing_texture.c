/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:00:16 by aliberal          #+#    #+#             */
/*   Updated: 2025/07/22 22:43:47 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

static int	ft_path_texture(char *str, char **texture, t_cub *cub, int j)
{
	cub->i = 0;
	if (*texture != NULL)
		cub->error = 2;
	if (ft_charinstr(str, '.') == 0 || ft_charinstr(str, '/') == 0
		|| ft_strlen2(str) <= 2)
		cub->error = 3;
	while (str[j] != '.')
	{
		if (str[j] != ' ' && str[j] != '.' && str[j] != '\t')
			cub->error = 3;
		j++;
	}
	*texture = (char *)(malloc(sizeof(char) * (ft_strlen2(str) + 1)));
	if (!(*texture))
		cub->error = 4;
	while (str[j] != '\0')
	{
		(*texture)[cub->i] = str[j];
		cub->i++;
		j++;
	}
	(*texture)[cub->i] = '\0';
	return (0);
}

void	ft_texture(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	if (str && str[i] == 'S' && str[i + 1] == 'O')
		ft_path_texture(str, &cub->so, cub, 2);
	else if (str && str[i] == 'N' && str[i + 1] == 'O')
		ft_path_texture(str, &cub->no, cub, 2);
	else if (str && str[i] == 'E' && str[i + 1] == 'A')
		ft_path_texture(str, &cub->ea, cub, 2);
	else if (str && str[i] == 'W' && str[i + 1] == 'E')
		ft_path_texture(str, &cub->we, cub, 2);
	else if (str && str[0] != 'N' && str[0] != 'S'
		&& str[0] != 'W' && str[0] != 'E'
		&& str[0] != 'R' && str[0] != 'F' && str[0] != 'C'
		&& str[0] > 65 && str[0] < 122)
		cub->error = 5;
}
