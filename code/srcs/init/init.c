/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:59:07 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/08 01:56:29 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int		ft_cub(char *str, t_cub *cub)
{
	int			i;
	int			y;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			ft_error(cub, "Invalid map name\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
	{
		if (ft_parsing(str, cub))
			exit(EXIT_FAILURE);
		if (!ft_verify_errors(cub))
			{
				printf("\n\n\n################ DADOS DO MAPA ################");
				printf("\n RESOLUCAO EM X: %d", cub->rx);
				printf("\n RESOLUCAO EM Y: %d", cub->ry);
				printf("\n\n TEXTURA DO NORTE: %s", cub->textures.NO);
				printf("\n TEXTURA DO SUL: %s", cub->textures.SO);
				printf("\n TEXTURA DO LESTE: %s", cub->textures.EA);
				printf("\n TEXTURA DO OESTE: %s", cub->textures.WE);
				printf("\n\n COR DO TETO: %d, %d, %d", cub->f_color[0], cub->f_color[1], cub->f_color[2]);
				printf("\n COR DO CHAO: %d, %d, %d", cub->c_color[0], cub->c_color[1], cub->c_color[2]);
				printf("\n\n NUMERO DE LINHAS: %d", cub->map.height);
				printf("\n TAMANHO DA LINHA: %d", cub->map.width);
				printf("\n\n POSICAO DO JOGADOR: X - %d | Y - %d", cub->player.x, cub->player.y);
				printf("\n\n DIRECAO DO JOGADOR:  %c\n\n", cub->player.dir);

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
	}	
	else
		ft_error(cub, "Invalid map name\n");
	return (0);
}

void	ft_initialisation(t_cub *cub)
{
	cub->rx = 0;
	cub->ry = 0;
	
	cub->textures.NO = NULL;
	cub->textures.SO = NULL;
	cub->textures.WE = NULL;
	cub->textures.EA = NULL;
    
    cub->f_color[0] = -1;
	cub->f_color[1] = -1;
	cub->f_color[2] = -1;
    cub->c_color[0] = -1;
	cub->c_color[1] = -1;
	cub->c_color[2] = -1;
    cub->sum = 0;
    cub->checkColor = 0;
    
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
