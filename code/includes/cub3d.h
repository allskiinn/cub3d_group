/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:19:04 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/10 01:52:03 by aliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define FORWARD_W_Z	119
# define BACK_S_S		115
# define RIGHT_D_D		100
# define LEFT_A_Q		97
# define BUFFER_SIZE	4096

typedef struct s_player
{
    int x;
    int y;
    char dir;
    int multiplayer;
} t_player;

typedef struct s_map {
    char **grid;
    int width;
    int height;
    int insidemap;
    int count;
    int wrongcharmap;
    int emptyline;
} t_map;


typedef struct s_ray
{
    double raydirx;
    double raydiry;
    double posx;
    double posy;
    double dirx;
    double diry;
    double planx;
    double plany;
    double camerax;
    
    int mapx;
    int mapy;
    double sidedistx;
    double sidedisty;
    double deltadistx;
    double deltadisty;
    int stepx;
    int stepy;
    int hit;
    int side;
    double perpwalldist;
    int lineheight;
    int drawstart;
    int drawend;
    double	movespeed;
	double	rotspeed;
    int x;
} t_ray;

typedef struct s_img
{
    void *img_ptr;
    int *addr;
    int bpp;
    int line_len;
    int endian;
    int	width;
	int	height;
} t_img;

typedef struct		s_color_texture
{
	int				texdir;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
}					t_color_texture;

typedef struct s_cub {
    int rx;
    int ry;
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    
    t_color_texture t;
    int f_color[3];
    int c_color[3];
    int f;
    int c;
    int sum;
    int checkColor;
    t_map map;
    t_player player;
    
    t_ray ray;           // raycasting
    t_img img;           // imagem atual
    t_img textures[4];
    void *mlx_ptr;
    void *mlx_win;

    // flags de movimento
    int forward;
    int back;
    int left;
    int right;
    int rotate_left;
    int rotate_right;

    int	screenx;
	int	screeny;
    
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


int		ft_check_player_around(t_cub *cub);


int		ft_space(t_cub *cub, int x , int y);

void	interior_map_errors(t_cub *cub, int error_code);
void	border_map_errors(t_cub *cub, int error_code);


void items_map_errors(t_cub *cub, int code);

int ft_verify_textures(t_cub *cub);
int	ft_tolower(int c);
int ft_verify_extention(char *t);
int ft_verify_ext_dir(char *dir);

int ret(t_cub *cub,char *str);

int		ft_mlx(t_cub *cub);
int		ft_raycasting(t_cub *cub);
void	ft_rotate_left(t_cub *cub, double olddirx);
void	ft_rotate_right_left(t_cub *cub);
void	ft_left_right(t_cub *cub);
void	ft_forward_back(t_cub *cub);
int		ft_color_column(t_cub *cub);
void	ft_stepsidedist(t_cub *cub);
void	ft_incrementray(t_cub *cub);
void	ft_drawstartend(t_cub *cub);
void	ft_initialisation3(t_cub *cub);
void	ft_init_more3(t_cub *cub);
int		ft_key_release(int keycode, t_cub *cub);
int		ft_key_press(int keycode, t_cub *cub);
void	ft_get_texture(t_cub *cub);
void	ft_get_texture_adress(t_cub *cub);
int		ft_exit(t_cub *cub);
void	ft_initialisation2(t_cub *cub);
void	ft_init_dir(t_cub *cub);

#endif
