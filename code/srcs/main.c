/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:48:16 by asobrinh          #+#    #+#             */
/*   Updated: 2025/06/06 15:47:41 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	ft_init(&cub);
	if (ac == 2)
		ft_cub(av[1], &cub);
	else
		write(1, "Error\nArguments invalides\n", 27);
}
