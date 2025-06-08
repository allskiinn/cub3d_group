/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:59:27 by aliberal          #+#    #+#             */
/*   Updated: 2025/06/08 21:07:50 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double	ft_calc_flashlight_intensity(t_cub *cub, int y)
{
	t_light	light;
	double	intensity;

	light.center_x = (double)cub->rx / 2.0;
	light.center_y = (double)cub->ry / 2.0;
	light.dx = (double)cub->ray.x - light.center_x;
	light.dy = (double)y - light.center_y;
	light.distance = sqrt(light.dx * light.dx + light.dy * light.dy);
	light.radius = 400.0;
	if (light.distance > light.radius)
	{
		intensity = 0.05;
	}
	else
	{
		intensity = fmax(0.7, \
			cos((light.distance / light.radius) * (M_PI / 2.0)));
	}
	if (light.distance < light.radius * 0.2)
		intensity += 0.5;
	if (intensity > 1.0)
		intensity = 1.0;
	return (intensity);
}

static void	ft_calc_texture_properties(t_cub *cub)
{
	cub->tex.texdir = ft_get_texdir(&cub->ray);
	if (cub->ray.side == 0)
	{
		cub->tex.wallx = cub->ray.posy \
			+ cub->ray.perpwalldist * cub->ray.raydiry;
	}
	else
	{
		cub->tex.wallx = cub->ray.posx \
			+ cub->ray.perpwalldist * cub->ray.raydirx;
	}
	cub->tex.wallx -= floor(cub->tex.wallx);
	cub->tex.step = 1.0 * cub->textures[0].height / cub->ray.lineheight;
	cub->tex.texx = (int)(cub->tex.wallx \
			* (double)cub->textures[cub->tex.texdir].width);
	if ((cub->ray.side == 0 && cub->ray.raydirx > 0)
		|| (cub->ray.side == 1 && cub->ray.raydiry < 0))
		cub->tex.texx = cub->textures[cub->tex.texdir].width \
			- cub->tex.texx - 1;
	cub->tex.texpos = (cub->ray.drawstart - cub->ry / 2 \
			+ cub->ray.lineheight / 2) * cub->tex.step;
}

static void	ft_apply_pixel_color(t_cub *cub, int x, int y, int tex_color)
{
	double	intensity;

	if (y >= cub->ry || x >= cub->rx)
	{
		return ;
	}
	if (!cub->mode)
	{
		cub->img.addr[y * cub->img.line_len / 4 + x] = tex_color;
	}
	else
	{
		intensity = ft_calc_flashlight_intensity(cub, y);
		cub->img.addr[y * cub->img.line_len / 4 + x] \
			= ((int)(((tex_color >> 16) & 0xFF) * intensity) << 16) \
			| ((int)(((tex_color >> 8) & 0xFF) * intensity) << 8) \
			| ((int)((tex_color & 0xFF) * intensity));
	}
}

static void	ft_draw_wall_loop(t_cub *cub, int x)
{
	int		y;
	int		tex_color;

	y = cub->ray.drawstart - 1;
	while (++y <= cub->ray.drawend)
	{
		cub->tex.texy = (int)cub->tex.texpos \
			& (cub->textures[cub->tex.texdir].height - 1);
		cub->tex.texpos += cub->tex.step;
		tex_color = cub->textures[cub->tex.texdir].addr[cub->tex.texy \
			* cub->textures[cub->tex.texdir].line_len / 4 \
			+ cub->tex.texx];
		ft_apply_pixel_color(cub, x, y, tex_color);
	}
}

int	ft_color_column(t_cub *cub)
{
	int		j;
	int		i;

	j = -1;
	i = cub->ry - cub->ray.drawstart;
	while (++j < cub->ray.drawstart)
	{
		cub->img.addr[j * cub->img.line_len / 4 + cub->ray.x] = cub->c;
	}
	if (j <= cub->ray.drawend)
	{
		ft_calc_texture_properties(cub);
		ft_draw_wall_loop(cub, cub->ray.x);
	}
	j = i;
	while (++j < cub->ry)
	{
		cub->img.addr[j * cub->img.line_len / 4 + cub->ray.x] = cub->f;
	}
	return (0);
}
