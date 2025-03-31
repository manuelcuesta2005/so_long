/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:11:38 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/03/05 16:11:45 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	alloc_map(char ***map, char *name_map, t_game *game)
{
	int		fd;
	char	*line;
	int		axis_y;

	*map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!*map)
		return ;
	fd = open(name_map, O_RDONLY);
	if (fd < 0)
	{
		free(*map);
		*map = NULL;
		return ;
	}
	axis_y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		(*map)[axis_y] = line;
		axis_y++;
		line = get_next_line(fd);
	}
	(*map)[axis_y] = NULL;
	close(fd);
}

char	**get_map(char *name_map, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;

	fd = open(name_map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	game->height = 0;
	game->width = 0;
	line = get_next_line(fd);
	if (line != NULL)
	{
		game->height++;
		game->width = ft_strlen(line) - 1;
	}
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			game->height++;
	}
	close(fd);
	alloc_map(&map, name_map, game);
	return (map);
}

int	is_valid_map(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	if (!game->map || game->height < 2 || game->width < 2)
		return (0);
	y = 0;
	map = game->map;
	while (y < game->height)
	{
		if ((((int)ft_strlen(map[y]) - 1) != game->width))
			return (0);
		x = 0;
		while (x < game->width)
		{
			if ((y == 0 || y == game->height - 1 || x == 0 || x == game->width
					- 1) && map[y][x] != '1')
				return (0);
			if (!ft_strchr("10PCE", map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	count_objects(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = game->map;
	game->collectable = 0;
	game->exit = 0;
	game->player = NULL;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (map[y][x] == 'C')
				game->collectable++;
			else if (map[y][x] == 'E')
				game->exit++;
			else if (map[y][x] == 'P')
				init_player(&game->player, x, y);
			x++;
		}
		y++;
	}
}

void	init_map(t_base *base, char *name_map)
{
	base->game->map = NULL;
	base->game->player = NULL;
	base->game->collectable = 0;
	base->game->exit = 0;
	base->game->moves = 0;
	base->game->map = get_map(name_map, base->game);
	if (!base->game->map || !is_valid_map(base->game))
		return (free_game(&base->game), free(base),
			print_error("Error: the map isn`t valid\n"));
	if (!is_map_playable(base->game))
		return (free_game(&base->game), free(base),
			print_error("Error: there are unattainable objects\n"));
	count_objects(base->game);
	if (base->game->collectable == 0 || !base->game->player
		|| base->game->exit != 1)
		return (free_game(&base->game), free(base),
			print_error("Error: missing objects in the map\n"));
}
