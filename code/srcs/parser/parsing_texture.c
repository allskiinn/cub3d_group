/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:00:16 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/04 18:27:40 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int ft_texture_error(t_cub *cub, char *message)
{

    return (ret(cub, message));
}

int ft_check_extension(const char *fname, const char *extensin) 
{
	const char	*ver;
	
	if (fname == NULL || extensin == NULL) 
	{
        		return (0);
        	}
    	ver = strrchr(fname, '.');
    	if (ver == NULL || ver == fname) 
    	{
        		return (0);
    	}
    	return (strcmp(ver + 1, extensin) == 0);
}

int ft_path_texture(char *str, char **texture, t_cub *cub, int j)
{
    cub->i = 0;
    if (*texture != NULL)
    {
        cub->error = 2;
        return (0);
    }
    while (str[j] == ' ')
        j++;

    char	*fname_start;
    char *ver;
    
    fname_start = &str[j];
    ver = strrchr(fname_start, '.');

    if (ver == NULL || ver == fname_start)
    {
        return (ft_texture_error(cub, "Error: Formato de arquivo de textura inválido. Extensão ausente ou inválida.\n"));
    }

    if (strcmp(ver + 1, "xpm") != 0)
    {
        return (ft_texture_error(cub, "Error: Formato de arquivo de textura inválido. Use um arquivo .xpm\n"));
    }

    if (!(*texture = (char *)(malloc(sizeof(char) * (ft_strlen2(fname_start) + 1)))))
    {
        cub->error = 2;
        return (0);
    }
    strcpy(*texture, fname_start);
    return (0);
}

void ft_texture(char *str, t_cub *cub)
{
    int i = 0;
    if (str && str[i] == 'S' && str[i + 1] == 'O')
        ft_path_texture(str, &cub->textures.SO, cub, 2);
    else if (str && str[i] == 'N' && str[i + 1] == 'O')
        ft_path_texture(str, &cub->textures.NO, cub, 2);
    else if (str && str[i] == 'E' && str[i + 1] == 'A')
        ft_path_texture(str, &cub->textures.EA, cub, 2);
    else if (str && str[i] == 'W' && str[i + 1] == 'E')
        ft_path_texture(str, &cub->textures.WE, cub, 2);
    else if (str && str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'
             && str[0] != 'R' && str[0] != 'F' && str[0] != 'C'
             && str[0] > 65 && str[0] < 122)
        cub->error = 2;
}
