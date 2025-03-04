/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 00:04:46 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/20 06:49:56 by tylerlover9      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}