/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:08:25 by asobrinh          #+#    #+#             */
/*   Updated: 2025/06/10 02:12:09 by aliberal         ###   ########.fr       */
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
		return (ret(cub, "Error: Invalid NO extension.\n"));
	else
		if (ft_verify_ext_dir(cub->no))
			return (ret(cub, "Error: Invalid NO texture path\n"));
	if (ft_verify_extention(cub->so))
		return (ret(cub, "Error: Invalid SO extension.\n"));
	else
		if (ft_verify_ext_dir(cub->so))
			return (ret(cub, "Error: Invalid SO texture path\n"));
	if (ft_verify_extention(cub->we))
		return (ret(cub, "Error: Invalid WE extension.\n"));
	else
		if (ft_verify_ext_dir(cub->we))
			return (ret(cub, "Error: Invalid WE texture path\n"));
	if (ft_verify_extention(cub->ea))
		return (ret(cub, "Error: Invalid EA extension.\n"));
	else
		if (ft_verify_ext_dir(cub->ea))
			return (ret(cub, "Error: Invalid EA texture path\n"));
	return (0);
}
