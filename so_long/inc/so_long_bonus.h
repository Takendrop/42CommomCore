/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:36:34 by jwozniak          #+#    #+#             */
/*   Updated: 2024/07/23 18:36:36 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <sys/time.h>

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define WINDOW_TITLE "so_long"
# define TILE_SIZE 32

# define N_SPRITES 5
# define N_WALK_FRAMES 8
# define FRAME_DURATION 0.1

typedef struct s_player
{
	int				pos[2];
	int				moves;
	int				cf;
	int				is_walking;
	int				is_facing_right;
	struct timeval	lft;
	void			*idle_right;
	void			*idle_left;
	void			*walk_right[N_WALK_FRAMES];
	void			*walk_left[N_WALK_FRAMES];
}	t_player;

typedef struct s_so_long
{
	void		*mlx;
	void		*win;
	int			w;
	int			h;
	int			map_fd;
	int			c_total;
	int			game_over;
	int			c_count;
	int			exit_found;
	char		*map_path;
	char		**map;
	char		**map_copy;
	void		*sprites[N_SPRITES];
	t_player	*p;
}	t_so_long;

//init functions
int		init_so_long(t_so_long *so_long);
int		init_map(int argc, char *argv[], t_so_long *so_long);
int		init_window(t_so_long *so_long);
int		load_sprites(t_so_long *so_long);

//parsing functions
int		make_path(char *relative_path, t_so_long *so_long);
int		fill_map_array(t_so_long *so_long);

//draw function
void	draw_all(t_so_long *so_long);

//hook function
int		handle_close(t_so_long *so_long);
int		key_hook(int keycode, t_so_long *so_long);

//player functions
int		player_check(t_so_long *so_long);
void	handle_move(t_so_long *so_long, int new_x, int new_y);

//map checks
int		collectible_check(t_so_long *so_long);
int		gate_check(t_so_long *so_long);
int		wall_check(t_so_long *so_long);
void	flood_fill(t_so_long *so_long, int x, int y);
int		validate_map(t_so_long *so_long);

//utils
int		count_lines(t_so_long *so_long);
void	print_map(t_so_long *so_long);
void	print_map_copy(char **map, int height);
void	error_msg(int error_n);
void	cleanup_player(t_so_long *so_long);
void	cleanup_map_and_path(t_so_long *so_long);
void	cleanup_window_and_display(t_so_long *so_long);
void	cleanup(t_so_long *so_long);

#endif
