/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:01:14 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/03/15 00:01:20 by mkettab          ###   ########.fr       */
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
				map->p_coord.y = y;
				map->p_coord.x = x;
			}
			x++;
		}
		y++;
	}
	if (count != 1)
		return (freeall(map->map), error_handle(P_NUMB));
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
		return (freeall(map->map), error_handle(E_NUMB));
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
		return (freeall(map->map), error_handle(C_NUMB));
	map->count_c = count;
}
