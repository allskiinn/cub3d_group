/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:22:34 by asobrinh          #+#    #+#             */
/*   Updated: 2025/07/27 08:27:03 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	ft_cub(char *str, t_cub *cub)
{
	if (!ft_check_cub_extension(str, cub))
		return (0);
	if (ft_parsing(str, cub))
		exit(EXIT_FAILURE);
	if (!ft_verify_errors(cub))
		ft_mlx(cub);
	return (0);
}

int	ft_check_cub_extension(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			ft_error(cub, "Invalid map name\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b'
		&& !str[i + 4])
		return (1);
	ft_error(cub, "Invalid map name\n");
	return (0);
}
