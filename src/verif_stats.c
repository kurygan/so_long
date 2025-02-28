/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:24:33 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/26 23:36:59y mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	verif_get_stats(t_map *map)
{
	verif_player(map);
	verif_exit(map);
	count_coins(map);
}

void	verif_player(t_map *map)
{
	int		count;
	int		x;
	int		y;
	char	**temp;

	temp = map->map;
	count = 0;
	y = 0;
	while (temp[y])
	{
		x = 0;
		while (temp[y][x])
		{
			if (temp[y][x] == 'P')
			{
				count++;
				map->player_base_cord_y = y;
				map->player_base_cord_x = x;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (ft_freeall(map->map), error_handle("1 Player Only!"));
}

void	verif_exit(t_map *map)
{
	int		count;
	int		x;
	int		y;
	char	**temp;

	temp = map->map;
	count = 0;
	y = 0;
	while (temp[y])
	{
		x = 0;
		while (temp[y][x])
		{
			if (temp[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
		return (ft_freeall(map->map), error_handle("1 Exit Only!"));
}

void	count_coins(t_map *map)
{
	int		count;
	int		x;
	int		y;
	char	**temp;

	temp = map->map;
	count = 0;
	y = 0;
	while (temp[y])
	{
		x = 0;
		while (temp[y][x])
		{
			if (temp[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	if (count == 0)
		return (ft_freeall(map->map), error_handle("1 collectible or more"));
	map->count_c = count;
}