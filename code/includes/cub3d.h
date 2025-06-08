/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:19:04 by aliberal          #+#    #+#             */
/*   Updated: 2025/05/12 12:24:27 by aliberal         ###   ########.fr       */
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
# define DARK_MODE		113
# define NORMAL_MODE	101
# define LEFT_A_Q		97
# define BUFFER_SIZE	4096

typedef struct s_player
{
	int		x;
	int		y;
	int		multiplayer;
	char	dir;
}			t_player;

typedef struct s_map
{
	int		width;
	int		height;
	int		insidemap;
	int		count;
	int		wrongcharmap;
	int		emptyline;
	char	**grid;
}			t_map;

typedef struct s_ray
{
	double	raydirx;
	double	raydiry;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
	double	camerax;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	movespeed;
	double	rotspeed;
	int		x;
}			t_ray;

typedef struct s_img
{
	void	*img_ptr;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_color_texture
{
	int		texdir;
	double	wallx;
	int		texx;
	int		texy;
	double	step;
	double	texpos;
}			t_color_texture;

typedef struct s_cub
{
	int				rx;
	int				ry;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	t_color_texture	tex;
	int				f_color[3];
	int				c_color[3];
	int				f;
	int				c;
	int				sum;
	int				checkcolor;
	t_map			map;
	t_player		player;
	t_ray			ray;
	t_img			img;
	t_img			textures[4];
	void			*mlx_ptr;
	void			*mlx_win;
	int				forward;
	int				back;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
	int				screenx;
	int				screeny;
	int				mode;
	int				error;
	int				i;
	int				j;
}			t_cub;

typedef struct s_gnl_params
{
	char		**buff;
	char		**line;
	t_cub		*cub;
	int			*copy_status;
}			t_gnl_params;

typedef struct s_light
{
	double	center_x;
	double	center_y;
	double	dx;
	double	dy;
	double	distance;
	double	radius;
	double	intensity;
}			t_light;

/*
** parsing functions
*/
int			ft_cub(char *str, t_cub *cub);
int			ft_parsing(char *file, t_cub *cub);
int			ft_is_map(char *str, t_cub *cub);
int			ft_copy_map(char *str, t_cub *cub);
void		ft_init(t_cub *cub);
void		ft_texture(char *str, t_cub *cub);
void		ft_map(char *str, t_cub *cub);
void		ft_color_resolution(char **str, t_cub *cub);
int			ft_check_cub_extension(char *str, t_cub *cub);
void		ft_print_map_data(t_cub *cub);

/*
** check map functions
*/
int			ft_charinstr(char *str, char c);
int			ft_emptyline(char *str);
int			ft_nb_comma(const char *str);
int			ft_walls(t_cub *cub);
int			ft_checkplayer(t_cub *cub);
int			ft_check_player_around(t_cub *cub);
int			ft_space(t_cub *cub, int x, int y);
int			ft_verify_textures(t_cub *cub);
int			ft_verify_extention(char *t);
int			ft_verify_ext_dir(char *dir);
int			ft_check_surroundings(t_cub *cub, int i, int j);
int			ft_check_right_col(t_cub *cub);
int			ft_check_left_col(t_cub *cub);
int			ft_check_left_col_spaces(t_cub *cub, int i);
int			ft_check_bottom_row(t_cub *cub);
int			ft_check_top_row(t_cub *cub);
int			ft_check_map_holes(t_cub *cub);

/*
** minilibx functions
*/
int			ft_mlx(t_cub *cub);

/*
** raycasting init
*/
void		ft_init2(t_cub *cub);
void		ft_init3(t_cub *cub);

/*
** raycasting main
*/
int			ft_raycasting(t_cub *cub);

/*
** raycasting moves
*/
void		ft_forward_back(t_cub *cub);
void		ft_left_right(t_cub *cub);
void		ft_rotate_right_left(t_cub *cub);

/*
** raycasting textures
*/
void		ft_get_texture(t_cub *cub);
int			ft_color_column(t_cub *cub);

/*
** raycasting steps
*/
void		ft_stepsidedist(t_cub *cub);
void		ft_load_texture_img(t_cub *cub, void **img_ptr,
				char *path, int idx); // Line break added
void		ft_get_texture(t_cub *cub);
int			ft_get_texdir(t_ray *ray);

/*
** key press
*/
int			ft_key_press(int keycode, t_cub *cub);
int			ft_key_release(int keycode, t_cub *cub);

/*
** utils functions
*/
int			get_next_line(int fd, char **line, t_cub *cub);
int			ft_strlen(char *str);
int			ft_atoi2(const char *str, t_cub *cub);
int			ft_strlen2(char *str);
int			ft_tolower(int c);
char		*ft_subbuff(char *buff, int start, int len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_atoi3(const char *str, t_cub *cub, char type);
void		ft_atoi3_skip_whitespace(const char *str, t_cub *cub);
int			ft_atoi3_parse_digits(const char *str, t_cub *cub);
void		ft_atoi3_assign_color(t_cub *cub, char type, int verify, int *c);
void		ft_atoi3_handle_spacing(const char *str, t_cub *cub);
void		ft_atoi3_process_component(const char *str, t_cub *cub,
				char type, int *c); // Line break added
int			ft_check(char *str);
int			ft_copy(char **line, char **buff);

/*
** error
*/
int			ft_verify_errors(t_cub *cub);
int			ret(t_cub *cub, char *str);
void		ft_error(t_cub *cub, char *str);
void		interior_map_errors(t_cub *cub, int error_code);
void		border_map_errors(t_cub *cub, int error_code);
void		items_map_errors(t_cub *cub, int code);

/*
** exit
*/
int			ft_exit(t_cub *cub);

#endif
