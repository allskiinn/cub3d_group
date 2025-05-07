/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_info_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:38:57 by asobrinh          #+#    #+#             */
/*   Updated: 2025/05/07 14:38:59 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void border_map_errors(t_cub *cub, int code)
{
	if (code == 1)
		ft_error(cub, "Error\nMap not closed at the top.\n");
	else if (code == 2)
		ft_error(cub, "Error\nPlayer on the top border.\n");
	else if (code == 3)
		ft_error(cub, "Error\nSpace found on the top border.\n");
	else if (code == 4)
		ft_error(cub, "Error\nMap not closed at the bottom.\n");
	else if (code == 5)
		ft_error(cub, "Error\nPlayer on the bottom border.\n");
	else if (code == 6)
		ft_error(cub, "Error\nSpace found on the bottom border.\n");
	else if (code >= 7)
		interior_map_errors(cub, code);
}

void interior_map_errors(t_cub *cub, int code)
{
	if (code == 7)
		ft_error(cub, "Error\nMap not closed on the left.\n");
	else if (code == 8)
		ft_error(cub, "Error\nPlayer on the left border.\n");
	else if (code == 9)
		ft_error(cub, "Error\nSpace on the left border leads outside.\n");
	else if (code == 10)
		ft_error(cub, "Error\nMap not closed on the right.\n");
	else if (code == 11)
		ft_error(cub, "Error\nPlayer on the right border.\n");
	else if (code == 12)
		ft_error(cub, "Error\nSpace on the right border leads outside.\n");
	else if (code == 13)
		ft_error(cub, "Error\nSpace above a path.\n");
	else if (code == 14)
		ft_error(cub, "Error\nSpace below a path.\n");
	else if (code == 15)
		ft_error(cub, "Error\nSpace to the left of a path.\n");
	else if (code == 16)
		ft_error(cub, "Error\nSpace to the right of a path.\n");
}
