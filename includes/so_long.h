/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:05:24 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/20 07:16:58 by tylerlover9      ###   ########.fr       */
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
# define BUFFER_SIZE 5

void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
bool	verify_format(char *str);

// GNL shit
typedef struct s_list
{
	char *content;
	struct s_list *next;
} t_list;

char	*get_next_line(int fd);
t_list	*ft_getlast(t_list *list);
int	ft_foundline(t_list *list);
int	read_and_stock(t_list **buf, int fd);
void	lst_clean(t_list **buf);
void	get_line_appart(t_list *buf, char **str);
void	stock_add(char *str, t_list **buf, int readed);
void	line_gen(char **str, t_list *buf);
int	ft_strlen	(char *str);
void	lst_free(t_list *lst);

#endif