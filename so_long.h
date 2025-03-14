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
}			t_game;

typedef struct s_base
{
	void	*mlx;
	void	*mlx_win;
	t_img	*mlx_img;
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
void		init_map(t_game *game, char *name_map);
// utils
void		free_map(char **map);
int			is_map_playable(t_game *game);
void		flood_fill(char **map, int x, int y, t_game *game);
// game
void		load_images(t_base *base);
void		render_map(t_base *base, t_game *game);
void		init_game(t_base *base, t_game *game);
#endif
