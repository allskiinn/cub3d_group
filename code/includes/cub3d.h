/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:19:04 by aliberal          #+#    #+#             */
/*   Updated: 2025/04/23 00:32:13 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"

// Para representar cores RGB
typedef struct s_color {
    int r;
    int g;
    int b;
} t_color;

// Estrutura principal para dados do mapa
typedef struct s_map {
    // Texturas
    char *texture_north;
    char *texture_south;
    char *texture_west;
    char *texture_east;

    // Cores
    t_color floor_color;
    t_color ceiling_color;

    // Mapa
    char **map;         // Array de strings (linhas do mapa)
    int map_width;
    int map_height;

    // Posição inicial do jogador
    int player_x;
    int player_y;
    char player_dir;    // 'N', 'S', 'E', 'W'

    int error;
} t_map;


#endif