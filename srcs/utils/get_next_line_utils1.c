/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrinh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:26:21 by asobrinh          #+#    #+#             */
/*   Updated: 2025/06/07 12:29:53 by asobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_copy_with_newline(char **line, char **buff, int start)
{
	char	*temp;
	char	*line_temp;

	temp = ft_substr(*buff, 0, start);
	line_temp = *line;
	*line = ft_strjoin(*line, temp);
	free(temp);
	free(line_temp);
	*buff = ft_subbuff(*buff, start + 1, (ft_strlen(*buff) - start));
	return (0);
}

static int	ft_copy_no_newline(char **line, char **buff)
{
	char	*temp;

	temp = NULL;
	if (*line)
		temp = *line;
	*line = ft_strjoin(*line, *buff);
	if (temp)
		free(temp);
	return (1);
}

int	ft_copy(char **line, char **buff)
{
	int		start;

	start = ft_check(*buff);
	if (start >= 0)
		return (ft_copy_with_newline(line, buff, start));
	else
		return (ft_copy_no_newline(line, buff));
	return (-1);
}
