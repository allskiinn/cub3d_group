/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:34:43 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/04 02:22:02 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int		ft_atoi2(const char *str, t_cub *cub)
{
	int		sum;

	sum = 0;
	if (str[1] != ' ' || ft_charinstr((char *)str, ',') == 1)
		cub->error = 2;
	while (str[cub->i] == ' ' || str[cub->i] == '\t'
			|| str[cub->i] == ',' || str[cub->i] == '\n'
			|| str[cub->i] == '\r' || str[cub->i] == '\v'
			|| str[cub->i] == '\f')
		cub->i++;
	if (str[cub->i] == '-' || str[cub->i] == '+')
		cub->error = 2;
	while (str[cub->i] >= '0' && str[cub->i] <= '9')
	{
		if (sum > 21474636)
			break ;
		sum = (sum * 10) + (str[cub->i] - 48);
		cub->i++;
	}
	while (str[cub->i] >= '0' && str[cub->i] <= '9')
		cub->i++;
	return (sum);
}

void	ft_atoi3_check(const char *str, t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != ',')
		i++;
	if (str[i] == ',')
		j = 1;
	i++;
	while (str[i] == ' ')
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
		cub->error = 2;
	if (ft_nb_comma(str) != 2)
		cub->error = 2;
}

void	ft_atoi3(const char *str, t_cub *cub, char type)
{
	int		verify;
	int		c;

	verify = 0;
	if (str[1] != ' ')
		cub->error = 2;
	ft_atoi3_check(str, cub);
	c = 0;
	while (str[cub->i] == ' ' || str[cub->i] == '\t' || str[cub->i]
			== ',' || str[cub->i] == '\n' || str[cub->i] == '\r'
			|| str[cub->i] == '\v' || str[cub->i] == '\f')
	{
		cub->i++;
		verify = 0;
        if (str[cub->i] >= '0' && str[cub->i] <= '9')
			cub->checkColor++;
		while (str[cub->i] >= '0' && str[cub->i] <= '9')
		{
			verify = (verify * 10) + str[cub->i] - 48;
			cub->sum = (cub->sum * 10) + (str[cub->i] - 48);
			cub->i++;
		}
		if (verify > 255 || verify < 0)
			cub->error = 2;
		else
		{
			if (type == 'F')
				cub->f_color[c++] = cub->sum;
			else if (type == 'C')
				cub->c_color[c++] = cub->sum;
		}
		cub->sum = 0;
	}
}

int		ft_charinstr(char *str, char c)
{
	int i;

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

int		ft_emptyline(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0' &&
				str[i] != '\n' && str[i] != '\r' && str[i] != '\v'
				&& str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}
