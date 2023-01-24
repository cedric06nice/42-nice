/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:55:36 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/24 20:50:17 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libmlx/mlx.h"

/* States */
# define EXIT_SUCCESS 0
# define EXIT_FALURE -1

/* Map */
# define COLLECTIBLE 'C'
# define EMPTY '0'
# define EXIT 'E'
# define PLAYER 'P'
# define WALL '1'

/* Graphics */
// # define HEADER_SIZE 0
# define TILE_SIZE 32
# define NB_IMG 5
# define COLLECTIBLE_IMG "./assets/collectible.xpm"
# define EMPTY_IMG "./assets/floor.xpm"
# define EXIT_CLOSE_IMG "./assets/door_close.xpm"
# define PLAYER_IMG "./assets/player_down.xpm"
# define WALL_IMG "./assets/wall.xpm"

/* Keys */
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define UP 13
# define ESC 53

typedef struct s_img
{
	void		*img[NB_IMG];
	int			img_width;
	int			img_height;
}				t_img;

typedef struct s_player
{
	int			position_x;
	int			position_y;
	int			nb_moves;
}				t_player;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*win_name;
	int			win_width;
	int			win_height;
	int			nb_rows;
	int			nb_cols;
	int			nb_players;
	int			nb_collectibles;
	int			nb_exits;
	int			exit_pos_x;
	int			exit_pos_y;
	char		**map;
	t_img		img;
	t_player	player;
}				t_mlx;

/* backtracking.c */
int 			bactracking(t_mlx *mlx_original);

/* errors.c */
void			exit_program_error(char *error);
void			exit_program_peacefully(t_mlx *mlx, char *error);
int				close_window(t_mlx *mlx);

/* graphics.c */
void			load_graphics(t_mlx *mlx);
int 			draw_graphics(t_mlx *mlx);

/* map_check.c */
int				check_arguments(int argc, char **argv);
int				check_map_size(t_mlx *mlx);
int				check_map_surroundings(t_mlx *mlx);
int				check_map_items(t_mlx *mlx);

/* map_set.c */
int				set_map_items(t_mlx *mlx);

/* map.c */
void			load_map(t_mlx *mlx, char *file);

/* player.c */
int				keyboard_key_pressed(int keycode, t_mlx *mlx);
void			player_direction(t_mlx *mlx, int keycode);
void			player_move(t_mlx *mlx, int to_x, int to_y);

/* print.c */
void			print_details(t_mlx *mlx);
void			print_map(t_mlx *mlx);

#endif
