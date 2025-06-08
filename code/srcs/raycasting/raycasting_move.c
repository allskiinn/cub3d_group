/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:15:39 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/10 16:17:13 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	void	ft_rotate_left(t_cub *cub, double olddirx)
{
	double oldplanex;

	if (cub->rotate_left == 1)
	{
		olddirx = cub->ray.dirx;
		oldplanex = cub->ray.planx;
		cub->ray.dirx = cub->ray.dirx * cos(cub->ray.rotspeed / 2) -
			cub->ray.diry * sin(cub->ray.rotspeed / 2);
		cub->ray.diry = olddirx * sin(cub->ray.rotspeed / 2) + cub->
			ray.diry * cos(cub->ray.rotspeed / 2);
		cub->ray.planx = cub->ray.planx * cos(cub->ray.rotspeed / 2) -
			cub->ray.plany * sin(cub->ray.rotspeed / 2);
		cub->ray.plany = oldplanex * sin(cub->ray.rotspeed / 2) +
			cub->ray.plany * cos(cub->ray.rotspeed / 2);
	}
}

void	ft_rotate_right_left(t_cub *cub)
{
	double oldplanx;
	double olddirx;

	oldplanx = cub->ray.planx;
	olddirx = cub->ray.dirx;
	if (cub->rotate_right == 1)
	{
		cub->ray.dirx = cub->ray.dirx * cos(-cub->ray.rotspeed / 2) -
			cub->ray.diry * sin(-cub->ray.rotspeed / 2);
		cub->ray.diry = olddirx * sin(-cub->ray.rotspeed / 2) +
			cub->ray.diry * cos(-cub->ray.rotspeed / 2);
		cub->ray.planx = cub->ray.planx * cos(-cub->ray.rotspeed / 2)
			- cub->ray.plany * sin(-cub->ray.rotspeed / 2);
		cub->ray.plany = oldplanx * sin(-cub->ray.rotspeed / 2) +
			cub->ray.plany * cos(-cub->ray.rotspeed / 2);
	}
	ft_rotate_left(cub, olddirx);
}

void	ft_forward_back(t_cub *cub)
{
	if (cub->forward == 1)
	{
		if (cub->map.grid[(int)(cub->ray.posx + (cub->ray.dirx * cub->
						ray.movespeed * 2))][(int)cub->ray.posy] == '0')
			cub->ray.posx += cub->ray.dirx * cub->ray.movespeed;
		if (cub->map.grid[(int)(cub->ray.posx)][(int)(cub->ray.posy +
					(cub->ray.diry * cub->ray.movespeed * 2))] == '0')
			cub->ray.posy += cub->ray.diry * cub->ray.movespeed;
	}
	if (cub->back == 1)
	{
		if (cub->map.grid[(int)(cub->ray.posx - (cub->ray.dirx * cub->
						ray.movespeed * 2))][(int)(cub->ray.posy)] == '0')
			cub->ray.posx -= cub->ray.dirx * cub->ray.movespeed;
		if (cub->map.grid[(int)(cub->ray.posx)][(int)(cub->ray.posy -
					(cub->ray.diry * cub->ray.movespeed * 2))] == '0')
			cub->ray.posy -= cub->ray.diry * cub->ray.movespeed;
	}
}

void	ft_left_right(t_cub *cub)
{
	if (cub->right == 1)
	{
		if (cub->map.grid[(int)(cub->ray.posx + cub->ray.diry *
					(cub->ray.movespeed * 2))][(int)cub->ray.posy] == '0')
			cub->ray.posx += cub->ray.diry * cub->ray.movespeed;
		if (cub->map.grid[(int)cub->ray.posx][(int)(cub->ray.posy -
					cub->ray.dirx *
					(cub->ray.movespeed * 2))] == '0')
			cub->ray.posy -= cub->ray.dirx * cub->ray.movespeed;
	}
	if (cub->left == 1)
	{
		if (cub->map.grid[(int)(cub->ray.posx - cub->ray.diry *
					(cub->ray.movespeed * 2))][(int)cub->ray.posy] == '0')
			cub->ray.posx -= cub->ray.diry * cub->ray.movespeed;
		if (cub->map.grid[(int)cub->ray.posx][(int)(cub->ray.posy +
					cub->ray.dirx *
					(cub->ray.movespeed * 2))] == '0')
			cub->ray.posy += cub->ray.dirx * cub->ray.movespeed;
	}
}
