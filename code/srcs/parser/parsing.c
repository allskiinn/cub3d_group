/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 00:23:21 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/07 16:31:33 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"


int ft_parsing_map(char *file, t_cub *cub)
{
    int fd;
    int status;
    char *str;

    fd = open(file, O_RDONLY);
    if (!(cub->map.grid = malloc(sizeof(char*) * cub->map.height)))
        return (0);
    status = 1;
    str = NULL;
    while (status != 0)
    {
        status = get_next_line(fd, &str, cub);
        if (cub->map.insidemap == 1 && ft_emptyline(str) == 0 &&
            cub->map.count < cub->map.height)
            cub->map.emptyline = 1;
        if ((cub->map.insidemap = ft_is_map(str, cub)) == 1)
        {
            cub->map.count++;
            ft_copy_map(str, cub);
        }
        free(str);
    }
    close(fd);
    return (0);
}

int ft_parsing(char *file, t_cub *cub)
{
    int fd;
    int status;
    char *str;

    str = NULL;
    status = 1;
    if ((fd = open(file, O_DIRECTORY)) != -1)
        ft_error(cub, "Error: Is a directory\n");
    if ((fd = open(file, O_RDONLY)) == -1)
        ft_error(cub, "Error: Could not open file\n");
    cub->error = 0;
    while (status != 0)
    {
        status = get_next_line(fd, &str, cub);
        if (cub->error == 2)
        {
            ft_error(cub, "Error: Parsing error\n");
            free(str);
            return (1);
        }
        ft_color_resolution(&str, cub);
        ft_texture(str, cub);
        ft_map(str, cub);
        free(str);
        str = NULL;
    }
    close(fd);
    if (cub->map.height == 0 || cub->map.width == 0)
        ft_error(cub, "Error: Map is missing\n");
    if (cub->textures.NO == NULL || cub->textures.SO == NULL || cub->textures.WE == NULL || cub->textures.EA == NULL)
        ft_error(cub, "Error: Missing texture path\n");
    ft_parsing_map(file, cub);
    return (0);
}
