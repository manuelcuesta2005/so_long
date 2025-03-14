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

	width = 42;
	height = 42;
	base->field = mlx_xpm_file_to_image(base->mlx, "../textures/field.xpm", &width, &height);
	base->collectable = mlx_xpm_file_to_image(base->mlx, "../textures/collectable.xpm", &width, &height);
	base->player = mlx_xpm_file_to_image(base->mlx, "../textures/player.xpm", &width, &height);
	base->exit_closed = mlx_xpm_file_to_image(base->mlx, "../textures/exit_closed.xpm", &width, &height);
	base->exit_closed = mlx_xpm_file_to_image(base->mlx, "../textures/exit_open.xpm", &width, &height);
	if (!base->field || !base->collectable || !base->player
		|| !base->exit_closed || !base->exit_open)
	{
		mlx_destroy_image(base->mlx, base->collectable);
		mlx_destroy_image(base->mlx, base->field);
		mlx_destroy_image(base->mlx, base->player);
		mlx_destroy_image(base->mlx, base->exit_closed);
		mlx_destroy_image(base->mlx, base->exit_open);
		return ;
	}
}

void	render_map(t_base *base, t_game *game)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = game->map;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (map[y][x] == '0')
				mlx_put_image_to_window(base->mlx, base->mlx_img, base->field,
					48, 48);
			if (map[y][x] == '1')
				mlx_put_image_to_window(base->mlx, base->mlx_img, base->wall,
					48, 48);
			if (map[y][x] == 'P')
				mlx_put_image_to_window(base->mlx, base->mlx_img, base->player,
					48, 48);
			if (map[y][x] == 'C')
				mlx_put_image_to_window(base->mlx, base->mlx_img,
					base->collectable, 48, 48);
			if (map[y][x] == 'E')
				mlx_put_image_to_window(base->mlx, base->mlx_img,
					base->exit_closed, 48, 48);
			x++;
		}
		y++;
	}
}

void	init_game(t_base *base, t_game *game)
{
	base->mlx = mlx_init();
	if (!base->mlx)
		return ;
	base->mlx_win = mlx_new_window(base->mlx, game->width, game->height,
			"so_long");
	if (!base->mlx_win)
		return ;
	load_images(base);
	render_map(base, game);
}
