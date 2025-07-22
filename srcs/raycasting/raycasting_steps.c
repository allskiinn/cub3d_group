/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:12:49 by aliberal          #+#    #+#             */
/*   Updated: 2025/07/22 21:46:21 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_drawstartend(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		cub->ray.perpwalldist = ((double)cub->ray.mapx \
			- cub->ray.posx \
			+ (1 - (double)cub->ray.stepx) / 2) \
			/ cub->ray.raydirx;
	}
	else
	{
		cub->ray.perpwalldist = ((double)cub->ray.mapy \
			- cub->ray.posy \
			+ (1 - (double)cub->ray.stepy) / 2) \
			/ cub->ray.raydiry;
	}
	if (cub->ray.perpwalldist == 0)
		cub->ray.perpwalldist = 0.0001;
	cub->ray.lineheight = (int)(cub->ry / cub->ray.perpwalldist);
	cub->ray.drawstart = -cub->ray.lineheight / 2 + cub->ry / 2;
	if (cub->ray.drawstart < 0)
		cub->ray.drawstart = 0;
	cub->ray.drawend = cub->ray.lineheight / 2 + cub->ry / 2;
	if (cub->ray.drawend >= cub->ry || cub->ray.drawend < 0)
		cub->ray.drawend = cub->ry - 1;
}

static void	ft_incrementray(t_cub *cub)
{
	while (cub->ray.hit == 0)
	{
		if (cub->ray.sidedistx < cub->ray.sidedisty)
		{
			cub->ray.sidedistx += cub->ray.deltadistx;
			cub->ray.mapx += cub->ray.stepx;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.sidedisty += cub->ray.deltadisty;
			cub->ray.mapy += cub->ray.stepy;
			cub->ray.side = 1;
		}
		if (cub->map.grid[cub->ray.mapy][cub->ray.mapx] == '1')
			cub->ray.hit = 1;
	}
	ft_drawstartend(cub);
}

void	ft_stepsidedist(t_cub *cub)
{
	if (cub->ray.raydirx < 0)
	{
		cub->ray.stepx = -1;
		cub->ray.sidedistx = (cub->ray.posx - cub->ray.mapx) \
			* cub->ray.deltadistx;
	}
	else
	{
		cub->ray.stepx = 1;
		cub->ray.sidedistx = (cub->ray.mapx + 1.0 - cub->ray.posx) \
			* cub->ray.deltadistx;
	}
	if (cub->ray.raydiry < 0)
	{
		cub->ray.stepy = -1;
		cub->ray.sidedisty = (cub->ray.posy - cub->ray.mapy) \
			* cub->ray.deltadisty;
	}
	else
	{
		cub->ray.stepy = 1;
		cub->ray.sidedisty = (cub->ray.mapy + 1.0 - cub->ray.posy) \
			* cub->ray.deltadisty;
	}
	ft_incrementray(cub);
}
