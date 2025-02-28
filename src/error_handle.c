/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:35:53 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/28 02:56:51 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_handle(char *error)
{
	//ft_putstr_fd("Error\n", 2);
	//ft_putstr_fd("--  ", 2);
	ft_putstr_fd(error, 2);
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