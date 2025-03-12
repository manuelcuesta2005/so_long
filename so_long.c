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
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Uso: %s <archivo.ber>", argv[0]);
		return (0);
	}
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		ft_printf("Error al asignar memoria para el juego\n");
		return (1);
	}
	init_map(game, argv[1]);
	free(game);
	return (0);
}
