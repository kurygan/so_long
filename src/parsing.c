/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:01:11 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/28 03:23:07 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	verify_map(t_map *map)
{
	verif_char(map->map);
	verif_lenght(map->map);
	verif_walls(map->map);
	verif_get_stats(map);
}

void	verif_char(char **map)
{
	int	x;
	int y;
	char	**temp;
	temp = map;
	y = 0;
	while(temp[y])
	{
		x = 0;
		while (temp[y][x])
		{
			if (temp[y][x] != '1' && temp[y][x] != '0' && temp[y][x] != 'E' && temp[y][x] != 'P' && temp[y][x] != 'C')
				return (ft_freeall(map), error_handle("Put only allowed char"));
			x++;
		}
		y++;
	}
}

void	verif_lenght(char **map)
{
	int		base_len;
	char	**temp;

	if (!map || !*map)
		return ;
	base_len = ft_strlen(*map);
	temp = map;
	while (*temp)
	{
		if (ft_strlen(*temp) != base_len)
		{
			ft_freeall(map);
			error_handle("This is not a rectangle :|");
		}
		temp++;
	}
}
