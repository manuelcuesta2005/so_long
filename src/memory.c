/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:36:06 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/03/18 16:36:07 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	free_map(char ***map)
{
	int	i;

	i = 0;
	if (!map || !(*map))
		return ;
	while ((*map)[i])
	{
		free((*map)[i]);
		(*map)[i] = NULL;
		i++;
	}
	free(*map);
	*map = NULL;
}

void	free_game(t_game **game)
{
	if (!game || !(*game))
		return ;
	if ((*game)->player)
	{
		free((*game)->player);
		(*game)->player = NULL;
	}
	free_map(&((*game)->map));
	free(*game);
	*game = NULL;
}

void	free_base(t_base **base)
{
	if (!base || !(*base))
		return ;
	if ((*base)->mlx)
	{
		if ((*base)->mlx_win)
		{
			mlx_destroy_window((*base)->mlx, (*base)->mlx_win);
			(*base)->mlx_win = NULL;
		}
		mlx_destroy_display((*base)->mlx);
		free((*base)->mlx);
		(*base)->mlx = NULL;
	}
	free(*base);
	*base = NULL;
}
