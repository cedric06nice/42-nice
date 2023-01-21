/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpugnair <cpugnair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:55:36 by cpugnair          #+#    #+#             */
/*   Updated: 2023/01/21 09:01:27 by cpugnair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libmlx/mlx.h"

/* Map */
# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

/* Graphics */
# define TILE_SIZE 32

/* Keys */
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define UP 13
# define ESC 53

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
	int			nb_exits;
	int			nb_collectibles;
	int			nb_moves;
	char		**map;
}				t_mlx;

/* errors.c */
int				print_errors(char *error);
void			exit_program(t_mlx *mlx, char *error);

/* set_map.c */
void 			set_map_size(t_mlx *mlx, char *file);
int				set_map_items(t_mlx *mlx);

/* check_map.c */
int				check_arguments(int argc, char **argv);
int				check_map_size(t_mlx *mlx);
int				check_map_surroundings(t_mlx *mlx);
int				check_map_items(t_mlx *mlx);

/* map.c */
void			load_map(t_mlx *mlx, char *file);

#endif
