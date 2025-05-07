/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:48:16 by asobrinh          #+#    #+#             */
/*   Updated: 2025/05/07 16:41:10 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int main(int ac, char **av)
{
    t_cub cub;

    ft_initialisation(&cub);
    if (ac == 2)
    {
        if (!ft_check_extension(av[1], "cub"))
        {
            fprintf(stderr, "Error: O arquivo de mapa deve ter a extensão .cub\n");
            return (1);
        }
        if (ft_parsing(av[1], &cub) == 0)
        {
            if (ft_verify_errors(&cub) != 0)
            {
                // A função ft_error já foi chamada dentro de ft_verify_errors
                return (1);
            }
            // Se chegou aqui, o parsing e a verificação foram bem-sucedidos
            // Continue com a lógica do seu jogo (inicialização do MLX, etc.)
            printf("Parsing e verificação bem-sucedidos!\n"); // Placeholder
        }
        else
        {
            // ft_error já foi chamada dentro de ft_parsing
            return (1);
        }
    }
    else
    {
        write(1, "Error\nArguments invalides\n", 27);
        return (1);
    }
    return (0);
}
