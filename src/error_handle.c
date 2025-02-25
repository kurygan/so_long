/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:35:53 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/24 23:56:36 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_handle(t_error_handle error)
{
	if (error == map_format)
		ft_putstr_fd("Wrong map Format, get a brain!\n", 2);
	else if (error == map_nf)
		ft_putstr_fd("Error 404: Map not Found!\n", 2);
	else if (error == wrong_args)
		ft_putstr_fd("You forgot to put a map :|.\n", 2);
	else if (error == map_n_rect)
		ft_putstr_fd("It's not a rectangle fwewot :|\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_freeall(char **map)
{
	char **temp;

	temp = map;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(map);
	map = NULL;
}