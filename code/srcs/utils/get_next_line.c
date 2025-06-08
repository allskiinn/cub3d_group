/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:49:24 by ebourdit          #+#    #+#             */
/*   Updated: 2025/05/08 02:22:09 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_eof(int ret, char **buff, char **line)
{
	if (ret == -1)
		return (-1);
	free(*buff);
	*buff = NULL;
	if (!*line)
	{
		*line = malloc(sizeof(char) * 1);
		if (!*line)
			return (-1);
		*line[0] = 0;
	}
	return (0);
}

static int	ft_init_buff(char **buff_ptr)
{
	if (!(*buff_ptr))
	{
		*buff_ptr = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!(*buff_ptr))
			return (-1);
	}
	return (0);
}

static int	ft_gnl_initial_setup(int fd, t_gnl_params *p)
{
	if (p->cub->error && *(p->buff))
	{
		free(*(p->buff));
		return (0);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || !p->line)
		return (-1);
	*(p->line) = NULL;
	*(p->copy_status) = 1;
	if (*(p->buff))
	{
		*(p->copy_status) = ft_copy(p->line, p->buff);
		if (*(p->copy_status) == 0)
			return (1);
	}
	if (ft_init_buff(p->buff) == -1)
		return (-1);
	return (42);
}

static int	ft_process_read_and_status(int fd, t_gnl_params *p,
	int *read_bytes_ptr)
{
	*read_bytes_ptr = read(fd, *(p->buff), BUFFER_SIZE);
	if (*read_bytes_ptr < 0)
		return (-1);
	if (*read_bytes_ptr == 0)
		return (ft_eof(*read_bytes_ptr, p->buff, p->line));
	(*(p->buff))[*read_bytes_ptr] = '\0';
	*(p->copy_status) = ft_copy(p->line, p->buff);
	if (*(p->copy_status) == 0)
		return (1);
	return (42);
}

int	get_next_line(int fd, char **line, t_cub *cub)
{
	static char		*buff = NULL;
	int				read_bytes;
	int				ret_code;
	int				copy_status;
	t_gnl_params	params;

	params.buff = &buff;
	params.line = line;
	params.cub = cub;
	params.copy_status = &copy_status;
	ret_code = ft_gnl_initial_setup(fd, &params);
	if (ret_code != 42)
		return (ret_code);
	while (1)
	{
		ret_code = ft_process_read_and_status(fd, &params, &read_bytes);
		if (ret_code != 42)
			return (ret_code);
	}
}
