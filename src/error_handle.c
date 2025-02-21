/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 23:35:53 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/21 02:34:00 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_handle(t_error_handle error)
{
	if (error == map_format)
		ft_putstr_fd("Wrong map Format, prends toi un cerveau!\n", 2);
	else if (error == map_nf)
		ft_putstr_fd("Error 404: Map not Found!\n", 2);
	else if (error == wrong_args)
		ft_putstr_fd("Wrond number of arguments.\n", 2);
	exit(EXIT_FAILURE);
}