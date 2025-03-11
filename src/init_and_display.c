/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:33:52 by mkettab           #+#    #+#             */
/*   Updated: 2025/03/07 18:38:49 by tylerlover9      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_cep(t_game *game)
{
	size_t	y;

	y = 0;
	while(y < game->collectible->count)
		mlx_set_instance_depth(&game->collectible->instances[y++], 5);
	y = 0;
	while(y < game->exit->count)
		mlx_set_instance_depth(&game->exit->instances[y++], 5);
	y = 0;
	while(y < game->player->count)
		mlx_set_instance_depth(&game->player->instances[y++], 5);
}

void	init_and_display(t_game *game, t_map *map)
{
	int	x;
	int	y;

	init_textures(game);
	y = -1;
	while (map->map[++y] && y < map->len.y)
	{
		x = -1;
		while (map->map[y][++x] && x < map->len.x)
		{
			if(map->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->collectible, x * 128, y * 128);
			else if(map->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->exit, x * 128, y * 128);
			else if(map->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->player, x * 128, y * 128);
			if (map->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->wall, x * 128, y * 128);
			else
				mlx_image_to_window(game->mlx, game->floor, x * 128, y * 128);
		}
		set_cep(game);
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