/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:07:37 by aliberal          #+#    #+#             */
/*   Updated: 2025/06/06 15:46:09 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_key_press(int keycode, t_cub *cub)
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
	else if (keycode == DARK_MODE)
		cub->mode = 1;
	else if (keycode == NORMAL_MODE)
		cub->mode = 0;
	else if (keycode == 65307)
		ft_error(cub, "Game over!\n");
	return (1);
}

int	ft_key_release(int keycode, t_cub *cub)
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
