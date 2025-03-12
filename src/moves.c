/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 02:07:34 by mkettab           #+#    #+#             */
/*   Updated: 2025/03/12 02:32:57 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_collectible(t_game *game)
{
	size_t	i;
	int		collectible_x;
	int		collectible_y;

	game->curr_c--;
	game->map[game->p.y][game->p.x] = '0';
	i = 0;
	while (i < game->collectible->count)
	{
		collectible_x = game->collectible->instances[i].x;
		collectible_y = game->collectible->instances[i].y;
		if (collectible_x == game->p.x * 128
			&& collectible_y == game->p.y * 128)
		{
			game->collectible->instances[i].enabled = false;
			break ;
		}
		i++;
	}
}

static void	check_victory(t_game *game)
{
	char	pos;

	pos = game->map[game->p.y][game->p.x];
	if (pos == 'C')
		get_collectible(game);
	if (pos == 'E' && game->curr_c == 0)
		return (ft_putstr_fd("ggwp", 1), mlx_close_window(game->mlx));
}

static void	update_pos(mlx_key_data_t key, t_game *game)
{
	if (key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		(game->p.y)--;
	else if (key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
		(game->p.x)--;
	else if (key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		(game->p.y)++;
	else if (key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
		(game->p.x)++;
	putnbr(++(game->move_count));
	ft_putstr_fd("\n", 1);
	check_victory(game);
}

static int	movement_valid(mlx_key_data_t key, t_game *game)
{
	int	x;
	int	y;

	x = game->p.x;
	y = game->p.y;
	if (key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		y--;
	else if (key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
		x--;
	else if (key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		y++;
	else if (key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
		x++;
	else
		return (0);
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'E' && game->curr_c > 0)
		return (0);
	return (1);
}

void	ft_hook(mlx_key_data_t key, void *param)
{
	t_game	*game;

	game = param;
	if (key.action == MLX_PRESS || key.action == MLX_REPEAT)
	{
		if (key.key == MLX_KEY_ESCAPE)
			return (mlx_close_window(game->mlx));
		if (movement_valid(key, game) == 1)
			update_pos(key, game);
		game->player->instances[0].x = game->p.x * 128;
		game->player->instances[0].y = game->p.y * 128;
	}
}