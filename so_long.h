/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:12:45 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/03/05 16:12:51 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_axis
{
	int		x;
	int		y;
}			t_axis;

typedef struct s_game
{
	char	**map;
	int		height;
	int		width;
	t_axis	*player;
	int		collectable;
	int		exit;
	int		moves;
}			t_game;

typedef struct s_base
{
	void	*mlx;
	void	*mlx_win;
	t_game	*game;
	t_img	*player;
	t_img	*exit_closed;
	t_img	*exit_open;
	t_img	*collectable;
	t_img	*field;
	t_img	*wall;

}			t_base;

// maps
void		alloc_map(char ***map, char *name_map, t_game *game);
char		**get_map(char *name_map, t_game *game);
int			is_valid_map(t_game *game);
void		count_objects(t_game *game);
void		init_map(t_base *base, char *name_map);
void		free_map(char ***map);
int			is_map_playable(t_game *game);
void		flood_fill(char **map, int x, int y, t_game *game);
// utils
void		print_image(t_base *base, t_img *img, int *x, int *y);
void		destroy_images(t_base *base);
void		print_error(char *str);
int			close_window(t_game *game, t_base *base, char *str);
void		free_game(t_game **game);
void		free_base(t_base **base);
void		state_door(t_game *game, t_base *base, int *x, int *y);
// game
void		load_images(t_base *base);
void		render_map(t_base *base, t_game *game);
void		init_game(t_base *base, t_game *game);
void		draw_background_for_counter(t_base *base);
// player
int			can_move(t_game *game, int new_x, int new_y);
void		move_player(t_game *game, int pos_x, int pos_y, t_base *base);
int			key_hook(int keycode, t_base *base);
void		init_player(t_axis **player, int x, int y);
#endif
