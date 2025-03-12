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

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

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

int	valid_path(t_game *game)
{
	char	**map_copy;
	int		y;
	int		x;

	map_copy = (char **)malloc(sizeof(char *) * game->height);
	y = 0;
	while (y++ < game->height)
		map_copy[y] = ft_strdup(game->map[y]);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				flood_fill(map_copy, x, y, game);
				break ;
			}
			x++;
		}
		y++;
	}
	y = 0;
	while (y < game->height)
	{
		if (ft_strchr(map_copy[y], 'C') || ft_strchr(map_copy[y], 'E'))
		{
			free_map(map_copy);
			return (0);
		}
		y++;
	}
	free_map(map_copy);
	return (1);
}
