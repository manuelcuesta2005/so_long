/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:18:41 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/03/07 12:18:43 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	is_valid_ber(char *filename)
{
	if (!filename || ft_strlen(filename) < 5)
	{
		print_error("Error: It is not an allowed file for the game\n");
		return (0);
	}
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4) != 0)
	{
		print_error("Error: Only .ber files are allowed\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_base	*base;

	if (argc != 2)
	{
		ft_putstr("Usage: ./so_long <map_file.ber>\n");
		return (1);
	}
	if (!is_valid_ber(argv[1]))
		return (0);
	base = malloc(sizeof(t_base));
	if (!base)
		print_error("Error de asignaciòn de memoria");
	base->game = malloc(sizeof(t_game));
	if (!base->game)
	{
		free(base);
		print_error("Error de asignaciòn de memoria al juego");
	}
	base->game->map = NULL;
	init_map(base, argv[1]);
	if (base->game->map)
		init_game(base, base->game);
	free_base(&base);
	return (0);
}
