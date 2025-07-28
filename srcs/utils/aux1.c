/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:34:43 by aliberal          #+#    #+#             */
/*   Updated: 2025/07/27 08:23:31 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void	ft_atoi3_check(const char *str, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != ',')
		i++;
	if (str[i] == ',')
		j = 1;
	i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while ((str[i] < '0' || str[i] > '9') && str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		cub->error = 8;
	if (ft_nb_comma(str) != 2)
		cub->error = 8;
}

void	ft_atoi3(const char *str, t_cub *cub, char type)
{
	int	c;

	if (str[1] != ' ' && str[1] != '\t')
		cub->error = 9;
	ft_atoi3_check(str, cub);
	c = 0;
	while (str[cub->i] && c < 3 && cub->i != 0)
	{
		ft_atoi3_skip_whitespace(str, cub);
		if (!str[cub->i])
			break ;
		ft_atoi3_process_component(str, cub, type, &c);
	}
}

int	ft_charinstr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_emptyline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' '
			&& str[i] != '\0' && str[i] != '\n' && str[i] != '\r'
			&& str[i] != '\v' && str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}
