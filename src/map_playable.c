/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:49:55 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/03/08 15:49:57 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game->height
		|| map[y][x] == '1' || map[y][x] == 'x')
		return ;
	map[y][x] = 'x';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

char	**copy_map(char **map, t_game *game)
{
	char	**copy;
	int		y;

	copy = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < game->height)
	{
		copy[y] = ft_strdup(map[y]);
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

int	can_get_objs(t_game *game, char **map_copy, int *collect)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C' && map_copy[y][x] != 'x')
				(*collect)--;
			if (game->map[y][x] == 'E' && map_copy[y][x] != 'x')
			{
				free_map(&map_copy);
				return (0);
			}
			x++;
		}
		y++;
	}
	free_map(&map_copy);
	return (1);
}

int	is_map_playable(t_game *game)
{
	char	**map_copy;
	int		collectables_left;
	int		y;
	int		x;

	collectables_left = game->collectable;
	map_copy = copy_map(game->map, game);
	if (!map_copy)
		return (0);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
				flood_fill(map_copy, x, y, game);
			x++;
		}
		y++;
	}
	if (!can_get_objs(game, map_copy, &collectables_left))
		return (0);
	return (collectables_left == 0);
}
