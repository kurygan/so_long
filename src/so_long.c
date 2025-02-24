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
	char	**map;

	mlx = NULL;
	if (argc != 2)
		error_handle(wrong_args, false);
	if (verify_format(argv[1]) == false)
		error_handle(map_format, false);
	
	map = get_map(argv[1]);
	verify_map(map);

	mlx = mlx_init(1280, 720, "caca", true);
	if (!mlx)
		return(EXIT_FAILURE);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}