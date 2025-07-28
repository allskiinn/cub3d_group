/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_info_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:38:57 by asobrinh          #+#    #+#             */
/*   Updated: 2025/07/27 08:24:40 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void	border_map_errors(t_cub *cub, int code)
{
	if (code == 1)
		ft_error(cub, "Error\nMap not closed at top.\n");
	else if (code == 2)
		ft_error(cub, "Error\nPlayer on top border.\n");
	else if (code == 3)
		ft_error(cub, "Error\nSpace on top border.\n");
	else if (code == 4)
		ft_error(cub, "Error\nMap not closed at bottom.\n");
	else if (code == 5)
		ft_error(cub, "Error\nPlayer on bottom border.\n");
	else if (code == 6)
		ft_error(cub, "Error\nSpace on bottom border.\n");
	else if (code >= 7)
		interior_map_errors(cub, code);
}

static void	interior_border_errors(t_cub *cub, int code)
{
	if (code == 7)
		ft_error(cub, "Error\nMap not closed on left.\n");
	else if (code == 8)
		ft_error(cub, "Error\nPlayer on left border.\n");
	else if (code == 9)
		ft_error(cub, "Error\nSpace on left border.\n");
	else if (code == 10)
		ft_error(cub, "Error\nMap not closed on right.\n");
	else if (code == 11)
		ft_error(cub, "Error\nPlayer on right border.\n");
	else if (code == 12)
		ft_error(cub, "Error\nSpace on right border.\n");
}

void	interior_map_errors(t_cub *cub, int code)
{
	if (code == 13)
		ft_error(cub, "Error\nSpace above path.\n");
	else if (code == 14)
		ft_error(cub, "Error\nSpace below path.\n");
	else if (code == 15)
		ft_error(cub, "Error\nSpace to left of path.\n");
	else if (code == 16)
		ft_error(cub, "Error\nSpace to right of path.\n");
	else
		interior_border_errors(cub, code);
}

static void	items_map_errors_part1(t_cub *cub, int code)
{
	if (code == 1)
		ft_error(cub, "Error\nUndefined textures.\n");
	else if (code == 2)
		ft_error(cub, "Error\nDouble texture definition.\n");
	else if (code == 3)
		ft_error(cub, "Error\nInvalid texture syntax.\n");
	else if (code == 4)
		ft_error(cub, "Error\nTexture allocation failure.\n");
	else if (code == 5)
		ft_error(cub, "Error\nInvalid character.\n");
}

void	items_map_errors(t_cub *cub, int code)
{
	if (code == 8)
		ft_error(cub, "Error\nMissing colors.\n");
	else if (code == 9)
		ft_error(cub, "Error\nInvalid color syntax\n");
	else if (code == 10)
		ft_error(cub, "Error\ninvalid color number.\n");
	else if (code == 11)
		ft_error(cub, "Error\nElements after the map.\n");
	else
		items_map_errors_part1(cub, code);
}
