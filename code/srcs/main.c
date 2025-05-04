/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:48:16 by asobrinh          #+#    #+#             */
/*   Updated: 2025/05/04 20:09:16 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int		main(int ac, char **av)
{
	t_cub cub;

	ft_initialisation(&cub);
	if (ac == 2)
	{
		ft_cub(av[1], &cub);
		//if (!ft_verify_errors(&cub))
		//{
			printf("\n\n\n################ DADOS DO MAPA ################");
			printf("\n RESOLUCAO EM X: %d", cub.rx);
			printf("\n RESOLUCAO EM Y: %d", cub.ry);
			printf("\n\n TEXTURA DO NORTE: %s", cub.textures.NO);
			printf("\n TEXTURA DO SUL: %s", cub.textures.SO);
			printf("\n TEXTURA DO LESTE: %s", cub.textures.EA);
			printf("\n TEXTURA DO OESTE: %s", cub.textures.WE);
			printf("\n\n COR DO TETO: %d, %d, %d", cub.f_color[0], cub.f_color[1], cub.f_color[2]);
			printf("\n COR DO CHAO: %d, %d, %d", cub.c_color[0], cub.c_color[1], cub.c_color[2]);
			printf("\n\n NUMERO DE LINHAS: %d", cub.map.height);
			printf("\n TAMANHO DA LINHA: %d", cub.map.width);
			printf("\n\n POSICAO DO JOGADOR: X - %d | Y - %d", cub.player.x, cub.player.y);
			printf("\n\n DIRECAO DO JOGADOR:  %c\n\n", cub.player.dir);
			for (int i = 0; i < cub.map.height; i++){
				for (int y = 0; y < cub.map.width; y++)
					printf("%c", cub.map.grid[i][y]);
				printf("\n");	
			}
			ft_error(&cub, "Finish");
		//}
	}
	else
		write(1, "Error\nArguments invalides\n", 27);
}

