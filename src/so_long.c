/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:58:45 by mkettab           #+#    #+#             */
/*   Updated: 2025/03/15 00:01:14 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
		error_handle(ARGS);
	if (verify_format(argv[1]) == false)
		error_handle(EXT);
	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&game, 0, sizeof(t_game));
	map.map = get_map(argv[1], &map);
	verify_map(&map, &game);
	if (map.len.x > 30 || map.len.y > 16)
		return (freeall(map.map), error_handle(MAP_SIZE), 0);
	game.mlx = mlx_init(map.len.x * 128, map.len.y * 128, "ChurBum Adventure",
			true);
	if (!game.mlx)
		return (freeall(map.map), EXIT_FAILURE);
	init_and_display(&game, &map);
	game.map = map.map;
	mlx_key_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	freeall(map.map);
	return (EXIT_SUCCESS);
}
