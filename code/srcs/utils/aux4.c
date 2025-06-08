/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:09:11 by aliberal          #+#    #+#             */
/*   Updated: 2025/06/07 12:16:38 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	void	ft_init_dir(t_cub *cub)
{
	if (cub->player.dir == 'N')
		cub->ray.dirx = -1;
	if (cub->player.dir == 'S')
		cub->ray.dirx = 1;
	if (cub->player.dir == 'E')
		cub->ray.diry = 1;
	if (cub->player.dir == 'W')
		cub->ray.diry = -1;
	if (cub->player.dir == 'N')
		cub->ray.plany = 0.66;
	if (cub->player.dir == 'S')
		cub->ray.plany = -0.66;
	if (cub->player.dir == 'E')
		cub->ray.planx = 0.66;
	if (cub->player.dir == 'W')
		cub->ray.planx = -0.66;
}

void	ft_init2(t_cub *cub)
{
	cub->forward = 0;
	cub->back = 0;
	cub->left = 0;
	cub->right = 0;
	cub->rotate_right = 0;
	cub->rotate_left = 0;
	cub->ray.posx = (double)cub->player.x + 0.5;
	cub->ray.posy = (double)cub->player.y + 0.5;
	cub->ray.dirx = 0;
	cub->ray.diry = 0;
	cub->ray.planx = 0;
	cub->ray.plany = 0;
	ft_init_dir(cub);
}

static	void	ft_init_more3(t_cub *cub)
{
	if (cub->ray.raydiry == 0)
		cub->ray.deltadistx = 0;
	else if (cub->ray.raydirx == 0)
		cub->ray.deltadistx = 1;
	else
		cub->ray.deltadistx = sqrt(1 + (cub->ray.raydiry
					* cub->ray.raydiry) / (cub->ray.raydirx
					* cub->ray.raydirx));
	if (cub->ray.raydirx == 0)
		cub->ray.deltadisty = 0;
	else if (cub->ray.raydiry == 0)
		cub->ray.deltadisty = 1;
	else
		cub->ray.deltadisty = sqrt(1 + (cub->ray.raydirx
					* cub->ray.raydirx) / (cub->ray.raydiry
					* cub->ray.raydiry));
}

void	ft_init3(t_cub *cub)
{
	cub->ray.hit = 0;
	cub->ray.perpwalldist = 0;
	cub->ray.camerax = 2 * cub->ray.x / (double)cub->rx - 1;
	cub->ray.raydirx = cub->ray.dirx + cub->ray.planx * \
						cub->ray.camerax;
	cub->ray.raydiry = cub->ray.diry + cub->ray.plany * \
						cub->ray.camerax;
	cub->ray.mapx = (int)cub->ray.posx;
	cub->ray.mapy = (int)cub->ray.posy;
	cub->ray.movespeed = 0.1;
	cub->ray.rotspeed = 0.033 * 1.8;
	ft_init_more3(cub);
}
