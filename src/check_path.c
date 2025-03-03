/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: rbaumann <rbaumann@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/03/02 01:07:15 by rbaumann          #+#    #+#             */
/*   Updated: 2025/03/02 01:07:15 by rbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->y_len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->y_len)
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

static void	flood_fill(char **map, int x, int y, int *collectibles,
		int *exit_reach)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'E')
	{
		*exit_reach = 1;
		return ;
	}
	if (map[y][x] == 'C')
		(*collectibles)--;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, collectibles, exit_reach);
	flood_fill(map, x - 1, y, collectibles, exit_reach);
	flood_fill(map, x, y + 1, collectibles, exit_reach);
	flood_fill(map, x, y - 1, collectibles, exit_reach);
}

void	check_path(t_map *map)
{
	char	**map_copy;
	int		c_count;
	int		exit_reach;
	int		i;

	c_count = map->count_c;
	exit_reach = 0;
	map_copy = copy_map(map);
	if (!map_copy)
		return (ft_freeall(map->map), exit(1));
	flood_fill(map_copy, map->p_base_x, map->p_base_y, &c_count, &exit_reach);
	i = 0;
	while (map_copy[i])
	{
		ft_putstr_fd(map_copy[i++], 1);
		ft_putstr_fd("\n", 1);
	}
	free_copy(map_copy, map->y_len);
	if (c_count > 0)
		return (ft_freeall(map->map),
			error_handle("Collectible not reachable"));
	if (!exit_reach)
		return (ft_freeall(map->map), error_handle("Exit not reachable"));
}
