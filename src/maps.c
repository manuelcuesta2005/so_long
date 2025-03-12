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
		(*map)[axis_y] = ft_strdup(line);
		free(line);
		axis_y++;
		line = get_next_line(fd);
	}
	(*map)[axis_y] = NULL;
	close(fd);
}

char	**get_map(char *name_map, t_game *game)
{
	int		fd;
	int		len;
	int		width;
	char	*line;
	char	**map;

	fd = open(name_map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	game->height = 0;
	width = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		if (len > width)
			width = len;
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	game->width = width;
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
		return (1);
	y = 0;
	map = game->map;
	while (y < game->height)
	{
		if (((int)ft_strlen(map[y]) != game->width))
			return (1);
		x = 0;
		while (x < game->width)
		{
			if ((y == 0 || y == game->height - 1 || x == 0 || x == game->width
					- 1) && map[y][x] != '1')
				return (1);
			if (!ft_strchr("10PCE", map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	if (!valid_path(game))
		return (1);
	return (0);
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
	game->player = 0;
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
				game->player++;
			x++;
		}
		y++;
	}
}
void print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	init_map(t_game *game, char *name_map)
{
	game->map = get_map(name_map, game);
	print_map(game->map);
	if (!is_valid_map(game) || !game->map)
	{
		ft_printf("Error: El mapa no es vàlido\n");
		free_map(game->map);
		game->map = NULL;
		return ;
	}
	count_objects(game);
	if (game->collectable == 0 || !game->player || game->exit != 1)
	{
		ft_printf("Error: el mapa necesita 1 jugador, al menos 1 coleccionable y una salida");
		free_map(game->map);
		game->map = NULL;
		return ;
	}
}
