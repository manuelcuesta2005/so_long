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

// int	main(void)
// {
// 	t_game	*game;

// 	game = (t_game *)malloc(sizeof(t_game));
// 	if (!game)
// 	{
// 		ft_printf("Error al asignar memoria para el juego\n");
// 		return (1);
// 	}
// 	game->map = get_map("maps/level1.ber", game);
// 	if (!game->map)
// 	{
// 		ft_printf("Error al cargar el mapa\n");
// 		free(game);
// 		return (1);
// 	}
// 	for (int i = 0; i < game->height; i++)
// 		ft_printf("%s", game->map[i]);
// 	ft_printf("Width of map: %d \n", game->width);
// 	ft_printf("Heigth of map: %d \n", game->height);
// 	is_valid_map(game);
// 	free(game->map);
// 	free(game);
// 	return (0);
// }

void	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	for (i = 0; i < game->height; i++)
		free(game->map[i]); // Liberar cada línea del mapa
	free(game->map);        // Liberar el array de punteros
}

int	main(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		ft_printf("Error al asignar memoria para el juego\n");
		return (1);
	}
	game->map = get_map("maps/level1.ber", game);
	if (!game->map)
	{
		ft_printf("Error al cargar el mapa\n");
		free(game);
		return (1);
	}
	free_map(game);
	free(game);
	return (0);
}
