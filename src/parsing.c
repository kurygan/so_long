/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:01:11 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/25 00:34:58 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	verify_map(char **map)
{
	verif_lenght(map);
	verif_walls(map);
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
			error_handle(map_n_rect);
		}
		temp++;
	}
}
