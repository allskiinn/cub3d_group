/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:59:27 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/11 00:29:26 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	void	ft_init_texture(t_cub *cub)
{
	if (cub->ray.side == 0 && cub->ray.raydirx < 0)
		cub->t.texdir = 0;
	if (cub->ray.side == 0 && cub->ray.raydirx >= 0)
		cub->t.texdir = 1;
	if (cub->ray.side == 1 && cub->ray.raydiry < 0)
		cub->t.texdir = 2;
	if (cub->ray.side == 1 && cub->ray.raydiry >= 0)
		cub->t.texdir = 3;
	if (cub->ray.side == 0)
		cub->t.wallx = cub->ray.posy + cub->ray.perpwalldist \
						* cub->ray.raydiry;
	else
		cub->t.wallx = cub->ray.posx + cub->ray.perpwalldist \
						* cub->ray.raydirx;
	cub->t.wallx -= floor((cub->t.wallx));
}

int	ft_apply_flashlight(t_cub *cub, int y, int color)
{
	int		center_x = cub->rx / 2;
	int		center_y = cub->ry / 2;
	int		dx = cub->ray.x - center_x;
	int		dy = y - center_y;
	double	distance = sqrt(dx * dx + dy * dy);
	double	radius = 400.0;
	double	intensity;

	// Transição suave e foco central mais forte
	if (distance > radius)
		intensity = 0.1;
	else
		intensity = fmax(0.6, cos((distance / radius) * (M_PI / 2)));

	// Simula um brilho mais intenso ao centro
	if (distance < radius * 0.2)
		intensity += 0.3;

	if (intensity > 1.0)
		intensity = 1.0;
	

	int	r = ((color >> 16) & 0xFF) * intensity ;
	int	g = ((color >> 8) & 0xFF) * intensity ;
	int	b = (color & 0xFF) * intensity;

	return ((r << 16) | (g << 8) | b);
}

static	void	ft_draw_texture(t_cub *cub, int x, int y)
{
	y = cub->ray.drawstart - 1;
	ft_init_texture(cub);
	cub->t.step = 1.0 * cub->textures[0].height / cub->ray.lineheight;
	cub->t.texx = (int)(cub->t.wallx * (double)cub->textures
			[cub->t.texdir].width);
	if (cub->ray.side == 0 && cub->ray.raydirx > 0)
		cub->t.texx = cub->textures[cub->t.texdir].width -
			cub->t.texx - 1;
	if (cub->ray.side == 1 && cub->ray.raydiry < 0)
		cub->t.texx = cub->textures[cub->t.texdir].width -
			cub->t.texx - 1;
	cub->t.texpos = (cub->ray.drawstart - cub->ry / 2 +
			cub->ray.lineheight / 2) * cub->t.step;
	while (++y <= cub->ray.drawend)
	{
		cub->t.texy = (int)cub->t.texpos &
			(cub->textures[cub->t.texdir].height - 1);
		cub->t.texpos += cub->t.step;
		if (!cub->mode)
		{
			if (y < cub->ry && x < cub->rx)
			cub->img.addr[y * cub->img.line_len / 4 + x] =
				cub->textures[cub->t.texdir].addr[cub->t.texy *
					cub->textures[cub->t.texdir].line_len /
					4 + cub->t.texx];
		} else
		{
			if (y < cub->ry && x < cub->rx)
			{
				int tex_color = cub->textures[cub->t.texdir].addr[
					cub->t.texy * cub->textures[cub->t.texdir].line_len / 4
					+ cub->t.texx];
				cub->img.addr[y * cub->img.line_len / 4 + x] =
					ft_apply_flashlight(cub, y, tex_color);
			}
		}
	}
}

int		ft_color_column(t_cub *cub)
{
	int j;
	int i;

	j = -1;
	cub->ray.drawend = cub->ry - cub->ray.drawstart;
	i = cub->ray.drawend;
	while (++j < cub->ray.drawstart)
		cub->img.addr[j * cub->img.line_len / 4 +
			cub->ray.x] = cub->c;
	if (j <= cub->ray.drawend)
		ft_draw_texture(cub, cub->ray.x, j);
	j = i;
	while (++j < cub->ry)
		cub->img.addr[j * cub->img.line_len / 4 +
			cub->ray.x] = cub->f;
	return (0);
}

static	void	ft_get_texture_adress(t_cub *cub)
{
	cub->textures[0].addr = (int *)mlx_get_data_addr(
			cub->textures[0].img_ptr, &cub->textures[0].bpp,
			&cub->textures[0].line_len, &cub->textures[0].endian);
	cub->textures[1].addr = (int *)mlx_get_data_addr(
			cub->textures[1].img_ptr, &cub->textures[1].bpp,
			&cub->textures[1].line_len, &cub->textures[1].endian);
	cub->textures[2].addr = (int *)mlx_get_data_addr(
			cub->textures[2].img_ptr, &cub->textures[2].bpp,
			&cub->textures[2].line_len, &cub->textures[2].endian);
	cub->textures[3].addr = (int *)mlx_get_data_addr(
			cub->textures[3].img_ptr, &cub->textures[3].bpp,
			&cub->textures[3].line_len, &cub->textures[3].endian);
}

void	ft_get_texture(t_cub *cub)
{
	if (!(cub->textures[0].img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr,
					cub->SO, &(cub->textures[0].width),
					&(cub->textures[0].height))))
		ft_error(cub, "Erro: Texture SO\n");
	if (!(cub->textures[1].img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr,
					cub->NO, &(cub->textures[1].width),
					&(cub->textures[1].height))))
		ft_error(cub, "Erro: Texture NO\n");
	if (!(cub->textures[2].img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr,
					cub->EA, &(cub->textures[2].width),
					&(cub->textures[2].height))))
		ft_error(cub, "Erro: Texture EA\n");
	if (!(cub->textures[3].img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr,
					cub->WE, &(cub->textures[3].width),
					&(cub->textures[3].height))))
		ft_error(cub, "Erro: Texture WE\n");
	ft_get_texture_adress(cub);
}
