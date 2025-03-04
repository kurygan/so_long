/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:08:08 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/20 06:47:08by tylerlover9      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_map	map;
	t_game	game;

	mlx = NULL;
	if (argc != 2)
		error_handle("YOU NEED 1 ARGUMENT");
	if (verify_format(argv[1]) == false)
		error_handle("The map's supposed to be .ber :|");
	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&game, 0, sizeof(t_game));
	map.map = get_map(argv[1], &map);
	verify_map(&map, &game);
	mlx = mlx_init(map.x_len * 128, map.y_len * 128, "caca", true);
	if (!mlx)
		return(ft_freeall(map.map), EXIT_FAILURE);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	ft_freeall(map.map);
	return (EXIT_SUCCESS);
}
