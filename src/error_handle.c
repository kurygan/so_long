/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:35:53 by mkettab           #+#    #+#             */
/*   Updated: 2025/03/14 23:57:13 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_handle(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("--  ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	freeall(char **map)
{
	char	**temp;

	temp = map;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(map);
	map = NULL;
}

void	freeimg(t_game *game)
{
	if (!game)
		return ;
	if (game->collectible)
		mlx_delete_image(game->mlx, game->collectible);
	if (game->player)
		mlx_delete_image(game->mlx, game->player);
	if (game->exit)
		mlx_delete_image(game->mlx, game->exit);
	if (game->floor)
		mlx_delete_image(game->mlx, game->floor);
	if (game->wall)
		mlx_delete_image(game->mlx, game->wall);
}
