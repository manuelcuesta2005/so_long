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

// maps
void		alloc_map(char ***map, char *name_map, t_game *game);
char		**get_map(char *name_map, t_game *game);
int			is_valid_map(t_game *game);
void		count_objects(t_game *game);
void		init_map(t_game *game, char *name_map);
// utils
void		free_map(char **map);
int			valid_path(t_game *game);
void		flood_fill(char **map, int x, int y, t_game *game);
#endif
