/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:33:52 by mkettab           #+#    #+#             */
/*   Updated: 2025/03/12 02:38:36 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	set_cep(t_game *game)
{
	size_t	y;

	y = 0;
	while(y < game->wall->count)
		game->wall->instances[y++].z = 0;
	y = 0;
	while(y < game->floor->count)
		game->floor->instances[y++].z = 0;
	y = 0;
	while(y < game->collectible->count)
		game->collectible->instances[y++].z = 5;
	y = 0;
	while(y < game->exit->count)
		game->exit->instances[y++].z = 5;
	y = 0;
	while(y < game->player->count)
		game->player->instances[y++].z =10;
}

static void	img_to_wd(t_game *game, int x, int y, t_map *map)
{
	if(map->map[y][x] == 'C')
	{
		if(mlx_image_to_window(game->mlx, game->collectible, x * 128, y * 128) <
			0)
			return (freeall(map->map), freeimg(game), error_handle(C_DISP));
	}
	else if(map->map[y][x] == 'E')
	{
		if(mlx_image_to_window(game->mlx, game->exit, x * 128, y * 128) < 0)
			return (freeall(map->map), freeimg(game), error_handle(E_DISP));
	}
	else if(map->map[y][x] == 'P')
	{
		if(mlx_image_to_window(game->mlx, game->player, x * 128, y * 128) < 0)
			return (freeall(map->map), freeimg(game), error_handle(P_DISP));
	}
	if (map->map[y][x] == '1')
	{
		if(mlx_image_to_window(game->mlx, game->wall, x * 128, y * 128) < 0)
			return (freeall(map->map), freeimg(game), error_handle(W_DISP));
	}
	else
		if(mlx_image_to_window(game->mlx, game->floor, x * 128, y * 128) < 0)
			return (freeall(map->map), freeimg(game), error_handle(F_DISP));
}

static mlx_image_t	*init_img(char *path, t_game *game)
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

static void	init_textures(t_game *game)
{
	game->player = init_img("./images/player.png", game);
	if (!game->player)
		return (freeall(game->map), freeimg(game), error_handle(IMG_LOAD));
	game->collectible = init_img("./images/collectible.png", game);
	if (!game->collectible)
		return (freeall(game->map), freeimg(game), error_handle(IMG_LOAD));
	game->exit = init_img("./images/exit.png", game);
	if (!game->exit)
		return (freeall(game->map), freeimg(game), error_handle(IMG_LOAD));
	game->floor = init_img("./images/floor.png", game);
	if (!game->floor)
		return (freeall(game->map), freeimg(game), error_handle(IMG_LOAD));
	game->wall = init_img("./images/wall.png", game);
	if (!game->wall)
		return (freeall(game->map), freeimg(game), error_handle(IMG_LOAD));
}


void	init_and_display(t_game *game, t_map *map)
{
	int	x;
	int	y;

	game->p.x = map->p_coord.x;
	game->p.y = map->p_coord.y;
	game->curr_c = map->count_c;
	init_textures(game);
	y = -1;
	while (map->map[++y] && y < map->len.y)
	{
		x = -1;
		while (map->map[y][++x] && x < map->len.x)
		{
			img_to_wd(game, x, y, map);
		}
		set_cep(game);
	}
}
