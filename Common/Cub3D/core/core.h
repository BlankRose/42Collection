/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:34:16 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/30 14:44:39 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_image {
	void	*img;
	char	*addr;
	t_uint	**pick;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_image;

typedef struct s_doublevector2 {
	double	x;
	double	y;
}	t_dvector2;

typedef struct s_player {
	t_dvector2	pos;
	t_dvector2	dir;
	t_dvector2	plane;
	float		pa;
}	t_ply;

typedef struct s_point {
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_raycast {
	t_dvector2	pos;
	double		camerax;
	t_dvector2	raydir;
	t_dvector2	side_d;
	t_dvector2	delta_d;
	t_vector2	map;
	t_vector2	step;
	t_vector2	draw;
	int			side;

	t_dvector2	v;
	t_vector2	w;
	t_vector2	text;
	t_dvector2	t_step;
	t_dvector2	tpos;
}	t_raycast;

typedef struct s_cub {
	void		*mlx_ptr;
	void		*mlx_win;
	t_image		*image;
	t_image		*minimap;
	t_image		*ply;
	t_ply		*player;
	char		**map;
	int			mapx;
	int			mapy;
	int			c_col;
	int			f_col;
	t_vector2	m_pos;
	double		time;
	double		oldtime;
	t_image		*no;
	t_image		*so;
	t_image		*we;
	t_image		*ea;
	t_raycast	*ray;
}	t_cub;

// SETTINGS

# define S_WIDTH 800
# define S_HEIGHT 600
# define S_PIXEL 8
# define SCALE 64
# define PI	3.1415926535f

# define MOVE_SPD 0.5f
# define ROT_SPD 0.1f
# define PRECISION 0.1

# define TEXT_WIDTH 32

// MATHS

int		ft_max1(int first, int second);
int		ft_mod1(int nbr);
float	cb_abs(float nbr);
double	cb_dabs(double nbr);

// PARSING

int		cb_isspaceline(char *line);
int		cb_isparamline(char *line);
void	cb_setxy(t_cub *cub);
int		cb_setcolor(char *arg, int red, int green, int blue);
int		cb_setparam(char *line, t_cub *cub);
int		cb_ismapline(char *line);
int		check_map(t_cub *cub, t_vector2 v, t_vector2 in);
void	cb_parsemap(char *path, t_cub *cub, int fd, char *line);
t_uint	**cb_convert_img(t_image *img);
t_image	*cb_load_asset(t_cub *cub, char *path);

// RUNTIME

void	cb_movement(int side, t_cub *cub);
void	cb_move_sides(int side, t_cub *cub);
void	cb_camera(int side, t_cub *cub, double spd);
void	cb_mlx_launch(t_cub *cub);
void	cb_raycast(t_cub *cub);

// DRAWING

void	cb_drawmap2d(t_cub *cub);
void	cb_drawplayerpoint(int color, t_cub *cub);
void	cb_drawrectangle(int x, int y, int color, t_cub *cub);
void	cb_drawvertline(double x, t_vector2 draw, int color, t_cub *cub);
void	ft_drawline(t_dvector2 p1, t_dvector2 p2, t_cub *cub);
void	img_pix_put(t_image *img, int x, int y, int color);
void	ft_drawplayer(t_cub *cub);
void	cb_drawtextline(t_cub *cub, int line_height, t_raycast *ray);
t_image	*cb_getwall(t_cub *cub, t_raycast *ray);

// INIT

void	cb_initminimap(t_cub *cub);
t_ply	*cb_initplayer(void);
t_cub	*cb_initcube(void);

// OTHER

void	ft_error(int flag);
int		cb_exit(int exitcode, t_cub *cub);
void	ft_freemem(char **arr);
int		cb_arraylen(char **arr);
int		cb_getrgb(int red, int green, int blue);
char	**ms_appendtoarr(char **arr, char *str);

#endif