/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:37:33 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/03/18 17:37:36 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	print_image(t_base *base, t_img *img, int *x, int *y)
{
	mlx_put_image_to_window(base->mlx, base->mlx_win, img, *x * 64, *y * 64);
}

void	destroy_images(t_base *base)
{
	if (base->collectable)
		mlx_destroy_image(base->mlx, base->collectable);
	if (base->field)
		mlx_destroy_image(base->mlx, base->field);
	if (base->player)
		mlx_destroy_image(base->mlx, base->player);
	if (base->exit_closed)
		mlx_destroy_image(base->mlx, base->exit_closed);
	if (base->exit_open)
		mlx_destroy_image(base->mlx, base->exit_open);
	if (base->wall)
		mlx_destroy_image(base->mlx, base->wall);
}

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int	close_window(t_game *game, t_base *base, char *str)
{
	ft_printf("%s\n", str);
	if (base)
		destroy_images(base);
	if (base)
	{
		free_base(&base);
		base = NULL;
	}
	if (game)
	{
		free_game(&game);
		game = NULL;
	}
	exit(0);
}

void	state_door(t_game *game, t_base *base, int *x, int *y)
{
	if (game->player && game->collectable == 0)
		print_image(base, base->exit_open, x, y);
	else
		print_image(base, base->exit_closed, x, y);
}
