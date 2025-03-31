/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:33:11 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/03/13 20:33:12 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	load_images(t_base *base)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	base->field = mlx_xpm_file_to_image(base->mlx, "textures/field.xpm", &width,
			&height);
	base->collectable = mlx_xpm_file_to_image(base->mlx,
			"textures/collectable.xpm", &width, &height);
	base->player = mlx_xpm_file_to_image(base->mlx, "textures/player.xpm",
			&width, &height);
	base->exit_closed = mlx_xpm_file_to_image(base->mlx,
			"textures/exit_closed.xpm", &width, &height);
	base->exit_open = mlx_xpm_file_to_image(base->mlx, "textures/exit_open.xpm",
			&width, &height);
	base->wall = mlx_xpm_file_to_image(base->mlx, "textures/wall.xpm", &width,
			&height);
	if (!base->field || !base->collectable || !base->player
		|| !base->exit_closed || !base->exit_open)
		destroy_images(base);
}

void	render_map(t_base *base, t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '0')
				print_image(base, base->field, &x, &y);
			if (game->map[y][x] == '1')
				print_image(base, base->wall, &x, &y);
			if (game->map[y][x] == 'P')
				print_image(base, base->player, &x, &y);
			if (game->map[y][x] == 'C')
				print_image(base, base->collectable, &x, &y);
			if (game->map[y][x] == 'E')
				state_door(game, base, &x, &y);
			x++;
		}
		y++;
	}
	draw_background_for_counter(base);
}

int	close_cross(t_base *base)
{
	ft_printf("Close the game...\n");
	if (base)
	{
		destroy_images(base);
		if (base->game)
		{
			free_map(&base->game->map);
			free_game(&base->game);
		}
		free_base(&base);
	}
	exit(0);
}

void	init_game(t_base *base, t_game *game)
{
	base->mlx = mlx_init();
	if (!base->mlx)
		print_error("Error: no se pudo inicializar la minilibx\n");
	base->mlx_win = mlx_new_window(base->mlx, game->width * 64, game->height
			* 64, "so_long");
	if (!base->mlx_win)
		print_error("Error: no se puedo crear la ventana\n");
	load_images(base);
	render_map(base, game);
	mlx_key_hook(base->mlx_win, key_hook, base);
	mlx_hook(base->mlx_win, 17, 0, close_cross, base);
	mlx_loop(base->mlx);
}
