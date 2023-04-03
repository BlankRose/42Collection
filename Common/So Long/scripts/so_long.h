/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:51:36 by flcollar          #+#    #+#             */
/*   Updated: 2022/03/25 18:50:44 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

/*********************************************************/
/*                                                       */
/*                     DEFINITIONS                       */
/*  Various macros for easier handling across functions  */
/*                                                       */
/*********************************************************/

/* Defines of every options for the project */

# define TITLE "Project: So long"
# define TILE_SIZE 32

# ifndef TILE_SET
#  define TILE_SET "10PECX"
# endif

# ifndef NAME
#  define NAME "so_long"
# endif

# ifndef WIN_RATIO
#  define WIN_RATIO 1
# endif

/* Defines of every avaible and used keycodes */

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

# define KEY_ESC 53

/*********************************************************/
/*                                                       */
/*                      STRUCTURES                       */
/*    Various structures for easier variable handling    */
/*                                                       */
/*********************************************************/

/* Structure to store various infos about specifics maps */
typedef struct s_map{
	char	*name;
	t_list	*data;
	size_t	in;
	size_t	item;
	size_t	out;
	size_t	len;
	size_t	height;
}	t_map;

/* Structure to store various about the player such as its
position and how many items he collected so far */
typedef struct s_player{
	size_t	item;
	int		x;
	int		y;
}	t_ply;

typedef struct s_img{
	void	*mlx;
	void	*img;
	char	*path;
	int		height;
	int		len;
}	t_img;

typedef struct s_textures{
	t_img	*entry;
	t_img	*exit;
	t_img	*item;
	t_img	*wall;
	t_img	*player;
}	t_pack;

/* Structure to store various infos about the currently
running windows and MLX details */
typedef struct s_mlx{
	void	*mlx;
	void	*window;
	size_t	win_height;
	size_t	win_len;
	t_pack	*sources;
}	t_mlx;

/* Structure for storing everything in one go */
typedef struct s_all{
	t_map	*map;
	t_mlx	*mlx;
	t_ply	*ply;
}	t_all;

/* Enum for listing every used KeyCodes */
// typedef enum e_keys{
// 	W = 13;
// 	A = 0;
// 	S = 1;
// 	D = 2;
// 	ESC = 53;
// 	UP = 126;
// 	LEFT = 123;
// 	DOWN = 125;
// 	RIGHT = 124;
// }	t_keys;

/*********************************************************/
/*                                                       */
/*                    PROGRAMM ONLY                      */
/*  Functions which are only used within this programm   */
/*                                                       */
/*********************************************************/

/* Initialize a whole complex map structure and instantly
inserts its data with LST and sets its NAME upon init
Return: newly created t_map */
t_map	sl_map_init(t_list *lst, char *name);

/* Load the map located within the file FD 
Return: Array of strings or NULL if allocations failed */
t_list	*sl_load_map(char *file);

/* Load the assets located within the folder assets
and stores loaded assets within MLX -> SOURCES
Return: 0 (FAIL) or 1 (PASS) */
int		sl_load_assets(t_mlx *mlx);

/* Load the region in the game */
void	sl_load_region(t_all *all);

/* Checks the validity of the MAP given
Return: 0 (PASS) or 1 (FAIL) */
int		sl_check_map(t_map *map, t_ply *ply);

/* Handles keyhooks provided by MLX */
int		sl_key_hook(int keycode, t_all *param);

/* Free the assets properly */
t_pack	*sl_free_pack(void *mlx, t_pack *src);

/* Move the player to POS, using the data META */
void	sl_move_player(t_all *meta, t_vector2 pos);

/* Print out an error message depending on the index ERR 
Return: 1 */
int		sl_error(int err, char *extra);

/* Closes the window and exits the programm */
int		sl_close(t_all *all);

/* Free everything of the current map to reach next programm */
int		sl_next_map(t_all *all);

/* Run an new window with MLX, using the loaded MAP
Return: 0 (PASS) or 1 (FAIL) */
int		sl_start(t_mlx *mlx, t_map *map, t_ply *ply);

#endif
