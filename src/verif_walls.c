/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:29:17 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/27 00:25:21 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	verif_walls(char **map)
{
	char	**temp;
	int		len;

	temp = map;
	verif_up_down(*temp, map);
	temp++;
	while (temp[1])
	{
		len = ft_strlen(*temp);
		if (len < 1 || (*temp)[0] != '1' || (*temp)[len - 1] != '1')
		{
			ft_freeall(map);
			error_handle("Walls is only made of '1'");
		}
		temp++;
	}
	verif_up_down(*temp, map);
}

void	verif_up_down(char *temp, char **map)
{
	while (*temp)
	{
		if (*temp != '1')
		{
			ft_freeall(map);
			error_handle("Walls is only made of '1'");
		}
		temp++;
	}
}