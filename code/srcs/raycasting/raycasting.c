/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:42:07 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/10 02:07:43 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_dir(t_cub *cub)
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

void	ft_initialisation2(t_cub *cub)
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

int		ft_exit(t_cub *cub)
{
	if (cub->img.img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->img.img_ptr);
	if (cub->textures[0].img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->textures[0].img_ptr);
	if (cub->textures[1].img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->textures[1].img_ptr);
	if (cub->textures[2].img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->textures[2].img_ptr);
	if (cub->textures[3].img_ptr)
		mlx_destroy_image(cub->mlx_ptr, cub->textures[3].img_ptr);
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx_ptr, cub->mlx_win);
	exit(0);
}

void	ft_get_texture_adress(t_cub *cub)
{
	cub->textures[0].addr = (int *)mlx_get_data_addr(cub->textures[0].img_ptr,
			&cub->textures[0].bpp,
			&cub->textures[0].line_len, &cub->textures[0].endian);
	cub->textures[1].addr = (int *)mlx_get_data_addr(cub->textures[1].img_ptr,
			&cub->textures[1].bpp,
			&cub->textures[1].line_len, &cub->textures[1].endian);
	cub->textures[2].addr = (int *)mlx_get_data_addr(cub->textures[2].img_ptr,
			&cub->textures[2].bpp,
			&cub->textures[2].line_len, &cub->textures[2].endian);
	cub->textures[3].addr = (int *)mlx_get_data_addr(cub->textures[3].img_ptr,
			&cub->textures[3].bpp,
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

int		ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == FORWARD_W_Z)
		cub->forward = 1;
	else if (keycode == BACK_S_S)
		cub->back = 1;
	else if (keycode == LEFT_A_Q)
		cub->left = 1;
	else if (keycode == RIGHT_D_D)
		cub->right = 1;
	else if (keycode == ROTATE_LEFT)
		cub->rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		cub->rotate_right = 1;
	else if (keycode == 65307)
		ft_error(cub, "Game over!\n");
	return (1);
}

int		ft_key_release(int keycode, t_cub *cub)
{
	if (keycode == FORWARD_W_Z)
		cub->forward = 0;
	else if (keycode == BACK_S_S)
		cub->back = 0;
	else if (keycode == LEFT_A_Q)
		cub->left = 0;
	else if (keycode == RIGHT_D_D)
		cub->right = 0;
	else if (keycode == ROTATE_LEFT)
		cub->rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		cub->rotate_right = 0;
	return (1);
}

void	ft_init_more3(t_cub *cub)
{
	if (cub->ray.raydiry == 0)
		cub->ray.deltadistx = 0;
	else if (cub->ray.raydirx == 0)
		cub->ray.deltadistx = 1;
	else
		cub->ray.deltadistx = sqrt(1 + (cub->ray.raydiry
			* cub->ray.raydiry) / (cub->ray.raydirx *
			cub->ray.raydirx));
	if (cub->ray.raydirx == 0)
		cub->ray.deltadisty = 0;
	else if (cub->ray.raydiry == 0)
		cub->ray.deltadisty = 1;
	else
		cub->ray.deltadisty = sqrt(1 + (cub->ray.raydirx *
			cub->ray.raydirx) / (cub->ray.raydiry *
			cub->ray.raydiry));
}

void	ft_initialisation3(t_cub *cub)
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

void	ft_drawstartend(t_cub *cub)
{
	if (cub->ray.side == 0)
		cub->ray.perpwalldist = ((double)cub->ray.mapx - \
				cub->ray.posx + (1 - (double)cub->ray.
				stepx) / 2) / cub->ray.raydirx;
	else
		cub->ray.perpwalldist = ((double)cub->ray.mapy - \
				cub->ray.posy + (1 - (double)cub->ray.
				stepy) / 2) / cub->ray.raydiry;
	cub->ray.lineheight = (int)(cub->ry / cub->ray.perpwalldist);
	cub->ray.drawstart = -cub->ray.lineheight / 2 + cub->ry / 2;
	if (cub->ray.drawstart < 0)
		cub->ray.drawstart = 0;
	cub->ray.drawend = cub->ray.lineheight / 2 + cub->ry / 2;
	if (cub->ray.drawend >= cub->ry || cub->ray.drawend < 0)
		cub->ray.drawend = cub->ry - 1;
}

void	ft_incrementray(t_cub *cub)
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
		if (cub->map.grid[cub->ray.mapx][cub->ray.mapy] == '1')
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

void	ft_init_texture(t_cub *cub)
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

void	ft_draw_texture(t_cub *cub, int x, int y)
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
		if (y < cub->ry && x < cub->rx)
			cub->img.addr[y * cub->img.line_len / 4 + x] =
				cub->textures[cub->t.texdir].addr[cub->t.texy *
					cub->textures[cub->t.texdir].line_len /
					4 + cub->t.texx];
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

void	ft_rotate_left(t_cub *cub, double olddirx)
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

int		ft_raycasting(t_cub *cub)
{
	cub->ray.x = 0;
	while (cub->ray.x < cub->rx)
	{
		ft_initialisation3(cub);
		ft_stepsidedist(cub);
		ft_color_column(cub);
		cub->ray.x++;
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->mlx_win,
			cub->img.img_ptr, 0, 0);
	ft_forward_back(cub);
	ft_left_right(cub);
	ft_rotate_right_left(cub);
	return (0);
}

int		ft_mlx(t_cub *cub)
{
	ft_initialisation2(cub);
	if (!(cub->mlx_ptr = mlx_init()))
		ft_error(cub, "Mlx init impossible\n");
	mlx_get_screen_size(cub->mlx_ptr, &cub->screenx, &cub->screeny);
	cub->rx = (cub->rx > cub->screenx) ? cub->screenx : cub->rx;
	cub->ry = (cub->ry > cub->screeny) ? cub->screeny : cub->ry;
	ft_get_texture(cub);
	cub->img.img_ptr = mlx_new_image(cub->mlx_ptr, cub->rx, cub->ry);
	cub->img.addr = (int *)mlx_get_data_addr(cub->img.img_ptr, &cub->img.bpp, &cub->img.line_len, &cub->img.endian);
	cub->mlx_win = mlx_new_window(cub->mlx_ptr, cub->rx,
			cub->ry, "Welcome!");
	mlx_hook(cub->mlx_win, 33, 1L << 17, ft_exit, cub);
	mlx_hook(cub->mlx_win, 2, 1L << 0, ft_key_press, cub);
	mlx_loop_hook(cub->mlx_ptr, ft_raycasting, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 1, ft_key_release, cub);
	mlx_loop(cub->mlx_ptr);
	return (0);
}