/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:08:08 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/20 01:38:27 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	mlx_t *mlx;

	mlx = NULL;
	if (argc != 2)
		return(1);
	if (verify_format(argv[1]) == false)
		return(1);

	mlx = mlx_init(1280, 720, "caca", true);
	if (!mlx)
		return(EXIT_FAILURE);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}