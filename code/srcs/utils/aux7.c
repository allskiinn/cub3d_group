/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:08:25 by asobrinh          #+#    #+#             */
/*   Updated: 2025/06/08 20:57:43 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	ft_verify_ext_dir(char *dir)
{
	int	fd;

	fd = open(dir, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	ft_verify_textures(t_cub *cub)
{
	if (ft_verify_extention(cub->no))
		return (ret(cub, "Error: Extensao no e invalida.\n"));
	else
		if (ft_verify_ext_dir(cub->no))
			return (ret(cub, "Error: Textura no nao existe no caminho.\n"));
	if (ft_verify_extention(cub->so))
		return (ret(cub, "Error: Extensao da textura so e invalida.\n"));
	else
		if (ft_verify_ext_dir(cub->so))
			return (ret(cub, "Error: Textura so nao existe no caminho.\n"));
	if (ft_verify_extention(cub->we))
		return (ret(cub, "Error: Extensao da textura we e invalida.\n"));
	else
		if (ft_verify_ext_dir(cub->we))
			return (ret(cub, "Error: Textura we nao existe no caminho.\n"));
	if (ft_verify_extention(cub->ea))
		return (ret(cub, "Error: Extensao da textura ea e invalida.\n"));
	else
		if (ft_verify_ext_dir(cub->ea))
			return (ret(cub, "Error: Textura ea nao existe no caminho.\n"));
	return (0);
}
