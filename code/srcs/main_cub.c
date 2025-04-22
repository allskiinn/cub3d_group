/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:48:16 by asobrinh          #+#    #+#             */
/*   Updated: 2025/03/29 13:48:18 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int main()
{
    t_structere abertura;

    inicializar(&abertura);
    mlx_hook(abertura.janela, 17, 0, feichada, &abertura);
    mlx_loop(abertura.mlx);

    return (0);
}
