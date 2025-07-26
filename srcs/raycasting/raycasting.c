/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:42:07 by aliberal          #+#    #+#             */
/*   Updated: 2025/07/25 19:29:01 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_raycasting(t_cub *cub)
{
	cub->ray.x = 0;
	while (cub->ray.x < cub->rx)
	{
		ft_init3(cub);
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

int	ft_mlx(t_cub *cub)
{
	ft_init2(cub);
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		ft_error(cub, "Mlx init impossible\n");
	mlx_get_screen_size(cub->mlx_ptr, &cub->screenx, &cub->screeny);
	if (cub->rx > cub->screenx)
		cub->rx = cub->screenx;
	if (cub->ry > cub->screeny)
		cub->ry = cub->screeny;
	ft_get_texture(cub);
	cub->img.img_ptr = mlx_new_image(cub->mlx_ptr, cub->rx, cub->ry);
	cub->img.addr = (int *)mlx_get_data_addr(cub->img.img_ptr,
			&cub->img.bpp, &cub->img.line_len, &cub->img.endian);
	cub->mlx_win = mlx_new_window(cub->mlx_ptr, cub->rx,
			cub->ry, "CUB3D GAME");
	mlx_loop_hook(cub->mlx_ptr, ft_raycasting, cub);
	mlx_hook(cub->mlx_win, 2, 1L << 0, ft_key_press, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 1, ft_key_release, cub);
	mlx_hook(cub->mlx_win, 33, 1L << 17, ft_exit, cub);
	mlx_loop(cub->mlx_ptr);
	return (0);
}
