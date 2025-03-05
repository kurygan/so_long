/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:58:45 by mkettab           #+#    #+#             */
/*   Updated: 2025/03/05 04:06:15 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void ft_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game = param;
	keydata.action = MLX_PRESS;

	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->player->instances[0].y -= 128;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->player->instances[0].y += 128;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->player->instances[0].x -= 128;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->player->instances[0].x += 128;
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
		error_handle("YOU NEED 1 ARGUMENT");
	if (verify_format(argv[1]) == false)
		error_handle("The map's supposed to be .ber :|");
	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&game, 0, sizeof(t_game));
	map.map = get_map(argv[1], &map);
	verify_map(&map, &game);
	if (map.x_len > 30 || map.y_len > 16)
		return (ft_freeall(map.map), error_handle("Map too big"), 0);
	game.mlx = mlx_init(map.x_len * 128, map.y_len * 128, "ChurBum Adventure", true);
	if (!game.mlx)
		return (ft_freeall(map.map), EXIT_FAILURE);
	init_and_display(&game, &map);
	mlx_key_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	ft_freeall(map.map);
	return (EXIT_SUCCESS);
}
