/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycsting_textura_util.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:39:38 by asobrinh          #+#    #+#             */
/*   Updated: 2025/06/07 15:39:42 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_load_texture_img(t_cub *cub, void **img_ptr, char *path, int idx)
{
	*img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, path,
			&(cub->textures[idx].width), &(cub->textures[idx].height));
	if (!(*img_ptr))
		ft_error(cub, "Erro: Texture\n");
	cub->textures[idx].img_ptr = *img_ptr;
	cub->textures[idx].addr = (int *)mlx_get_data_addr(
			cub->textures[idx].img_ptr, &cub->textures[idx].bpp,
			&cub->textures[idx].line_len, &cub->textures[idx].endian);
}

void	ft_get_texture(t_cub *cub)
{
	void	*img_ptr;

	ft_load_texture_img(cub, &img_ptr, cub->so, 0);
	ft_load_texture_img(cub, &img_ptr, cub->no, 1);
	ft_load_texture_img(cub, &img_ptr, cub->ea, 2);
	ft_load_texture_img(cub, &img_ptr, cub->we, 3);
}

int	ft_get_texdir(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->raydirx < 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (ray->raydiry < 0)
			return (2);
		else
			return (3);
	}
}
