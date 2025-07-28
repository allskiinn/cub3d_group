/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:59:07 by aliberal          #+#    #+#             */
/*   Updated: 2025/07/27 08:44:31 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void	ft_print_map_data(t_cub *cub)
{
	int	i;
	int	y;

	i = 0;
	while (i < cub->map.height)
	{
		y = 0;
		while (y < cub->map.width)
		{
			printf("%c", cub->map.grid[i][y]);
			y++;
		}
		printf("\n");
		i++;
	}
	printf("Mapa lido com sucesso...\n");
}

static void	ft_init_colors_map_props(t_cub *cub)
{
	cub->f_color[0] = -1;
	cub->f_color[1] = -1;
	cub->f_color[2] = -1;
	cub->c_color[0] = -1;
	cub->c_color[1] = -1;
	cub->c_color[2] = -1;
	cub->c = -1;
	cub->f = -1;
	cub->sum = 0;
	cub->checkcolor = 0;
	cub->map.grid = NULL;
	cub->map.width = 0;
	cub->map.height = 0;
	cub->map.emptyline = 0;
	cub->map.insidemap = 0;
	cub->map.count = 0;
	cub->map.wrongcharmap = 0;
	cub->error = 0;
	cub->player.x = -1;
	cub->player.y = -1;
	cub->player.dir = 'x';
	cub->player.multiplayer = 0;
}

static void	ft_init_mlx_textures(t_cub *cub)
{
	cub->img.img_ptr = NULL;
	cub->textures[0].img_ptr = NULL;
	cub->textures[1].img_ptr = NULL;
	cub->textures[2].img_ptr = NULL;
	cub->textures[3].img_ptr = NULL;
	cub->mlx_win = NULL;
	cub->mlx_ptr = NULL;
}

void	ft_init(t_cub *cub)
{
	cub->rx = 0;
	cub->ry = 0;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	ft_init_colors_map_props(cub);
	ft_init_mlx_textures(cub);
}
