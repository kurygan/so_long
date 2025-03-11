/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:01:14 by tylerlover9       #+#    #+#             */
/*   Updated: 2025/03/05 09:01:18 by tylerlover9      ###   ########.fr       */
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