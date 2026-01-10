/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:09:11 by aliberal          #+#    #+#             */
/*   Updated: 2026/01/09 19:15:55 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	void	ft_init_dir(t_cub *cub)
{
	if (cub->player.dir == 'N')
	{
		cub->diry = -1;
		cub->ray.planx = FOV;
	}
	if (cub->player.dir == 'S')
	{
		cub->diry = 1;
		cub->ray.planx = -cub->diry * FOV;
	}
	if (cub->player.dir == 'E')
	{
		cub->dirx = 1;
		cub->ray.plany = FOV;
	}
	if (cub->player.dir == 'W')
	{
		cub->dirx = -1;
		cub->ray.plany = -cub->dirx * FOV;
	}
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
	cub->dirx = 0;
	cub->diry = 0;
	cub->ray.planx = 0;
	cub->ray.plany = 0;
	ft_init_dir(cub);
}

static	void	ft_init_more3(t_cub *cub)
{
	if (cub->ray.raydirx == 0)
		cub->ray.deltadistx = 1e30;
	else
		cub->ray.deltadistx = fabs(1 / cub->ray.raydirx);
	if (cub->ray.raydiry == 0)
		cub->ray.deltadisty = 1e30;
	else
		cub->ray.deltadisty = fabs(1 / cub->ray.raydiry);
}

void	ft_init3(t_cub *cub)
{
	cub->ray.hit = 0;
	cub->ray.perpwalldist = 0;
	cub->ray.camerax = 2 * cub->ray.x / (double)cub->rx - 1;
	cub->ray.raydirx = cub->dirx + cub->ray.planx * cub->ray.camerax;
	cub->ray.raydiry = cub->diry + cub->ray.plany * cub->ray.camerax;
	cub->ray.mapx = (int)cub->ray.posx;
	cub->ray.mapy = (int)cub->ray.posy;
	cub->ray.movespeed = 0.1;
	cub->ray.rotspeed = 0.033;
	ft_init_more3(cub);
}
