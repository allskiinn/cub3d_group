/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_formataco_cores.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:32:54 by asobrinh          #+#    #+#             */
/*   Updated: 2025/03/29 17:33:05 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	verif_cor_certa(int r, int g, int b)
{
	if (r >= 0 && r <= 255 && g >= 0 && 
		g <= 255 && b >= 0 && b <= 255)
	{
		return (1);
	}
	return (0);
}

int	validar_formatacao_cor(const char *linha)
{
	const char	*ptr;
	char		*fim;
	int			cores[3];
	int			nc;

	ptr = linha;
	nc = 0;
	while (*ptr && isspace(*ptr))
		ptr++;
	if (*ptr != 'F' && *ptr != 'C')
	{
		write_error("The line must start with 'F' or 'C'.");
		return (0);
	}
	ptr++;
	while (*ptr && isspace(*ptr))
		ptr++;
	while (nc < 3)
	{
		if (!isdigit(*ptr))
		{
			write_error("Expected a number, but found another character.");
			return (0);
		}
		cores[nc] = ft_strtol(ptr, &fim, 10);
		if (fim == ptr)
		{
			write_error("Invalid number found.");
			return (0);
		}
		if (*fim == ' ')
		{
			write_error("There cannot be a space after a number before a comma.");
			return (0);
		}
		if (nc < 2)
		{
			if (*fim != ',')
			{
				write_error("A comma is missing between the numbers.");
				return (0);
			}
			fim++;
			while (*fim && isspace(*fim))
				fim++;
			if (!isdigit(*fim))
			{
				write_error("Expected a number after the comma.");
				return (0);
			}
		}
		else
		{
			if (*fim != '\0')
			{
				write_error("There cannot be spaces or characters after the last number.");
				return (0);
			}
		}
		ptr = fim;
		nc++;
	}
	if (!verif_cor_certa(cores[0], cores[1], cores[2]))
	{
		write_error("Color values must be between 0 and 255.");
		return (0);
	}
	return (1);
}

