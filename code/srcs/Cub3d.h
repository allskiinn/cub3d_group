/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:48:01 by asobrinh          #+#    #+#             */
/*   Updated: 2025/03/29 13:48:02 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>


#define LARGURA 1000
#define ALTURA 900

typedef struct s_structure
{
    void *mlx;
    void *janela;
} t_structere;

typedef struct s_textur
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int floor_r;
	int floor_g;
	int floor_b;
	int ceiling_r;
	int ceiling_g;
	int ceiling_b;
}t_textur;

void valid_arquivo(char nome, t_textur *padrao);
void inicializar(t_structere *abrir);
int feichada(void *jan);

int verifi_textura(char *lin, t_textur *padrao);
int validar_local_textura(char *local);


//feitas
int verif_cor_certa(int r, int g, int b);
int	validar_formatacao_cor(const char *linha)

#endif

