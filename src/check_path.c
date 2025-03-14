/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:06:34 by mkettab           #+#    #+#             */
/*   Updated: 2025/03/14 16:06:34 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->len.y + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->len.y)
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
			{
				free(copy[i]);
				copy[i] = NULL;
			}
			free(copy);
			copy = NULL;
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	free_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map_copy[i++]);
	free(map_copy);
}

static void	flood_fill(char **map, t_point pos, t_game *game)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'E')
	{
		game->exit_reached = true;
		return ;
	}
	if (map[y][x] == 'C')
		(game->curr_c)--;
	map[y][x] = 'F';
	flood_fill(map, (t_point){pos.x - 1, pos.y}, game);
	flood_fill(map, (t_point){pos.x + 1, pos.y}, game);
	flood_fill(map, (t_point){pos.x, pos.y - 1}, game);
	flood_fill(map, (t_point){pos.x, pos.y + 1}, game);
}

void	check_path(t_map *map, t_game *game)
{
	char	**map_copy;

	game->curr_c = map->count_c;
	game->exit_reached = false;
	map_copy = copy_map(map);
	if (!map_copy)
		return (freeall(map->map), exit(1));
	flood_fill(map_copy, map->p_coord, game);
	free_copy(map_copy, map->len.y);
	if (game->curr_c > 0)
		return (freeall(map->map),
			error_handle(C_N_REACH));
	game->curr_c = map->count_c;
	if (!game->exit_reached)
		return (freeall(map->map), error_handle(E_N_REACH));
}
