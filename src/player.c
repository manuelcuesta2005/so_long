/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:32:16 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/03/15 20:32:18 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	can_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->width || new_y < 0 || new_y >= game->height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	game->moves++;
	return (1);
}

void	move_player(t_game *game, int pos_x, int pos_y, t_base *base)
{
	t_axis		*player;
	int			x;
	int			y;
	static int	last_pos_was_exit = 0;

	player = game->player;
	x = player->x + pos_x;
	y = player->y + pos_y;
	if (can_move(game, x, y))
	{
		if (game->map[y][x] == 'C')
			game->collectable--;
		if (game->map[y][x] == 'E' && game->collectable == 0)
			close_window(game, base, "You win!!!");
		if (last_pos_was_exit)
			game->map[player->y][player->x] = 'E';
		else
			game->map[player->y][player->x] = '0';
		last_pos_was_exit = (game->map[y][x] == 'E');
		player->x = x;
		player->y = y;
		game->map[y][x] = 'P';
		ft_printf("moves: %d\n", game->moves);
		render_map(base, game);
	}
}

int	key_hook(int keycode, t_base *base)
{
	if (!base || !base->game)
		return (0);
	if (keycode == 65361 || keycode == 97)
		move_player(base->game, -1, 0, base);
	else if (keycode == 65362 || keycode == 119)
		move_player(base->game, 0, -1, base);
	else if (keycode == 65363 || keycode == 100)
		move_player(base->game, 1, 0, base);
	else if (keycode == 65364 || keycode == 115)
		move_player(base->game, 0, 1, base);
	else if (keycode == 65307)
		close_window(base->game, base, "Close the game...");
	return (0);
}

void	init_player(t_axis **player, int x, int y)
{
	(*player) = malloc(sizeof(t_axis));
	if (!(*player))
		return ;
	(*player)->x = x;
	(*player)->y = y;
}
