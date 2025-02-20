/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:05:24 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/19 01:30:56 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

# define E_FORMAT_MAP "Map format is wrong, you dumb shit!"

void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
bool	verify_format(char *str);

#endif