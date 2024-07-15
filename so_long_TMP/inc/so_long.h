/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:50:23 by jwozniak          #+#    #+#             */
/*   Updated: 2024/06/26 12:50:25 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/time.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define WINDOW_TITLE "so_long"
# define WINDOW_WIDTH 160
# define WINDOW_HEIGHT 160

# define TILE_SIZE 16
# define NUM_SPRITES 4

typedef struct s_player {
	int	x;
	int	y;
}	t_player;

typedef struct s_so_long {
	void	*mlx;
	void	*window;
	void	*img;
	char	*img_data;
	int	game_width;
	int	game_height;
	int		map_fd;
	char	*map_path;
	char	**map;
	void	*sprites[NUM_SPRITES];
	long long	last_timestamp;
	int		moves;
	t_player	*player;
}	t_so_long;

int	init_so_long(t_so_long *so_long);
int	init_map(int argc, char *argv[], t_so_long *so_long);
int	make_path(char *relative_path, t_so_long *so_long);
int	fill_map_array(t_so_long *so_long);

void	draw_block(int x, int y, void *sprite, t_so_long *so_long);
void	draw(t_so_long *so_long);
void	load_sprites(t_so_long *so_long);

int	close_window(t_so_long *so_long);

#endif
