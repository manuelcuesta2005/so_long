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

// int	main(int argc, char **argv)
// {
// 	t_game	*game;

// 	if (argc != 2)
// 	{
// 		ft_printf("Uso: %s <archivo.ber>\n", argv[0]);
// 		return (0);
// 	}
// 	game = (t_game *)malloc(sizeof(t_game));
// 	if (!game)
// 	{
// 		ft_printf("Error al asignar memoria para el juego\n");
// 		return (1);
// 	}
// 	game->map = NULL;
// 	game->width = 0;
// 	game->height = 0;
// 	game->collectable = 0;
// 	game->exit = 0;
// 	game->player = 0;
// 	init_map(game, argv[1]);
// 	free_map(game->map);
// 	free(game);
// 	return (0);
// }


int key_hook(int keycode, t_base *base)
{
    // Aquí manejas las teclas, como las flechas para mover al jugador
    if (keycode == 65307)  // ESC para salir
    {
        mlx_destroy_window(base->mlx, base->mlx_win);
        exit(0);
    }
    // Agregar más lógica para mover al jugador si es necesario
    return (0);
}

int main(int argc, char **argv)
{
    t_base base;
    t_game game;

    // Verifica los argumentos y carga el mapa aquí
    if (argc != 2)
    {
        ft_putstr("Usage: ./so_long <map_file>\n");
        return (1);
    }
	init_map(&game, argv[1]);
    init_game(&base, &game);  // Inicializa MLX, ventana y carga imágenes

    // Configura el hook para manejar eventos (como teclas)
    mlx_key_hook(base.mlx_win, key_hook, &game);

    // Esto mantiene la ventana abierta y esperando eventos
    mlx_loop(base.mlx);

    return (0);
}


