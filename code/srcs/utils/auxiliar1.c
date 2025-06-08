/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 11:22:48 by asobrinh          #+#    #+#             */
/*   Updated: 2025/06/07 11:23:03 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void	ft_atoi3_skip_whitespace(const char *str, t_cub *cub)
{
	while (str[cub->i] == ' ' || str[cub->i] == '\t' || str[cub->i] == ','
		|| str[cub->i] == '\n' || str[cub->i] == '\r'
		|| str[cub->i] == '\v' || str[cub->i] == '\f')
	{
		cub->i++;
	}
}

int	ft_atoi3_parse_digits(const char *str, t_cub *cub)
{
	int	verify;

	verify = 0;
	while (str[cub->i] >= '0' && str[cub->i] <= '9')
	{
		verify = (verify * 10) + str[cub->i] - 48;
		cub->sum = (cub->sum * 10) + (str[cub->i] - 48);
		cub->i++;
	}
	return (verify);
}

void	ft_atoi3_assign_color(t_cub *cub, char type, int verify, int *c)
{
	if (verify > 255 || verify < 0)
		cub->error = 10;
	else
	{
		if (type == 'F')
			cub->f_color[(*c)++] = cub->sum;
		else if (type == 'C')
			cub->c_color[(*c)++] = cub->sum;
	}
	cub->sum = 0;
}

void	ft_atoi3_handle_spacing(const char *str, t_cub *cub)
{
	while (str[cub->i] == ' ' || str[cub->i] == '\t')
		cub->i++;
	if (str[cub->i] == ',')
		cub->i++;
	while (str[cub->i] == ' ' || str[cub->i] == '\t')
		cub->i++;
}

void	ft_atoi3_process_component(const char *str, t_cub *cub,
			char type, int *c)
{
	int	verify;

	if (str[cub->i] >= '0' && str[cub->i] <= '9')
		cub->checkcolor++;
	else
	{
		cub->i = 0;
		return ;
	}
	verify = ft_atoi3_parse_digits(str, cub);
	ft_atoi3_assign_color(cub, type, verify, c);
	ft_atoi3_handle_spacing(str, cub);
}
