/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:33:52 by mkettab           #+#    #+#             */
/*   Updated: 2025/03/05 04:08:18 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_and_display(t_game *game, t_map *map)
{
	int	x;
	int	y;

	init_textures(game);
	y = -1;
	while (map->map[++y] && y < map->y_len)
	{
		x = -1;
		while (map->map[y][++x] && x < map->x_len)
		{
			if (map->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->wall, x * 128, y * 128);
			if (map->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->player, map->p_base_x * 128, map->p_base_y * 128);
			if (map->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->exit, x * 128, y * 128);
			if (map->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->collectible, x * 128, y * 128);
			if (map->map[y][x] == '0')
				mlx_image_to_window(game->mlx, game->floor, x * 128, y * 128);
		}
	}
}

void	init_textures(t_game *game)
{
	game->player = init_img("./images/player.png", game);
	game->collectible = init_img("./images/collectible.png", game);
	game->exit = init_img("./images/exit.png", game);
	game->floor = init_img("./images/floor.png", game);
	game->wall = init_img("./images/wall.png", game);
}

mlx_image_t	*init_img(char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	img = mlx_texture_to_image(game->mlx, texture);
	if (!img)
	{
		mlx_delete_texture(texture);
		return (NULL);
	}
	mlx_delete_texture(texture);
	return (img);
}