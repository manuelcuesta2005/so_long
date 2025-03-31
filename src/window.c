/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:05:03 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/03/26 16:05:04 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	draw_background_for_counter(t_base *base)
{
	int		i;
	int		j;
	char	*moves_str;

	i = 5;
	while (i < 5 + 150)
	{
		j = 5;
		while (j < 5 + 30)
		{
			mlx_pixel_put(base->mlx, base->mlx_win, i, j, 0x1e1e1e);
			j++;
		}
		i++;
	}
	moves_str = ft_itoa(base->game->moves);
	mlx_string_put(base->mlx, base->mlx_win, 15, 25, 0x228B22, "Moves: ");
	mlx_string_put(base->mlx, base->mlx_win, 75, 25, 0xFFFFFF, moves_str);
	free(moves_str);
}
