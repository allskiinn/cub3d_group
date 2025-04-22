/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_janela.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:52:36 by asobrinh          #+#    #+#             */
/*   Updated: 2025/03/29 13:52:38 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void inicializar(t_structere *abrir)
{
    abrir->mlx = mlx_init();
    if (abrir->mlx == NULL)
    {
        exit(1);
    }
    
    abrir->janela = mlx_new_window(abrir->mlx, LARGURA, ALTURA, "Cub3d");
    if (abrir->janela == NULL)
    {
        exit(1);
    }
}

int feichada(void *jan)
{
    t_structere	*abrir;
    
    abrir = (t_structere *)jan;
    mlx_destroy_window(abrir->mlx, abrir->janela);
    {
    	exit(0);
    }
    return (0);
}
