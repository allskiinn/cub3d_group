/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:19:04 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/07 16:32:26 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
#include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# define BUFFER_SIZE	4096

typedef struct s_player
{
    int x;
    int y;
    char dir;
    int multiplayer;
} t_player;

typedef struct s_texture
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;
} t_texture;

typedef struct s_map {
    char **grid;
    int width;
    int height;
    int insidemap;
    int count;
    int wrongcharmap;
    int emptyline;
} t_map;

typedef struct s_cub {
    int rx;
    int ry;
    t_texture textures;
    int f_color[3];
    int c_color[3];
    int sum;
    int checkColor;
    t_map map;
    t_player player;
    int error;
    int i;
    int j;
} t_cub;

void	ft_initialisation(t_cub *cub);
int		ft_cub(char *str, t_cub *cub);

int	    ft_parsing(char *file, t_cub *cub);
int		ft_parsing_map(char *file, t_cub *cub);
void	ft_texture(char *str, t_cub *cub);
int		ft_path_texture(char *str, char **texture, t_cub *cub, int j);
void	ft_map(char *str, t_cub *cub);
int		ft_is_map(char *str, t_cub *cub);
int		ft_copy_map(char *str, t_cub *cub);
int		ft_start(char c, t_cub *cub, int i, int j);
void	ft_color_resolution(char **str, t_cub *cub);

int		ft_atoi2(const char *str, t_cub *cub);
void	ft_atoi3(const char *str, t_cub *cub, char type);
int		ft_charinstr(char *str, char c);
int		ft_emptyline(char *str);
int		ft_nb_comma(const char *str);
int		ft_strlen2(char *str);
int		ft_walls(t_cub *cub);

void	ft_error(t_cub *cub, char *str);
int     ft_verify_errors(t_cub *cub);

int		get_next_line(int fd, char **line, t_cub *cub);
char		*ft_subbuff(char *buff, int start, int len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strlen(char *str);

int check_color(int color[3]);
int		ft_checkPlayer(t_cub *cub);

//tratei da parte que faltava da validacao do mapa em relacao a borda e detro do mapa


int		ft_check_player_around(t_cub *cub);


int		ft_space(t_cub *cub, int x , int y);

void	interior_map_errors(t_cub *cub, int error_code);
void	border_map_errors(t_cub *cub, int error_code);

int ft_check_extension(const char *fname, const char *extensin); // lider essa funcao verifica a extensao, para validar a extencao 
int ret(t_cub *cub, char *str);

#endif
