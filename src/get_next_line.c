/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:24:39 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/21 19:55:34y mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_next_line(int fd)
{
	static t_list	*buf;
	char			*fin_line;
	int				error;

	fin_line = NULL;
	error = read_and_stock(&buf, fd);
	if (0 == error)
		return (NULL);
	if (-1 == error)
		return (lst_clean(&buf), buf = NULL, error_handle("404: Map not Found!"), NULL);
	get_line_appart(buf, &fin_line);
	lst_clean(&buf);
	if (!(fin_line[0]))
	{
		lst_free(buf);
		buf = NULL;
		free(fin_line);
		return (NULL);
	}
	return (fin_line);
}

int	read_and_stock(t_list **buf, int fd)
{
	char	*str;
	int		readed;

	readed = 1;
	while (ft_foundline(*buf) && readed > 0)
	{
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return (0);
		readed = (int)read(fd, str, BUFFER_SIZE);
		if (-1 == readed)
			return (free(str), -1);
		if (!buf && !readed)
			return (free(str), 0);
		str[readed] = 0;
		stock_add(str, buf, readed);
		free(str);
	}
	return (1);
}

void	stock_add(char *str, t_list **buf, int readed)
{
	int		i;
	t_list	*last;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (readed + 1));
	if (new->content == NULL)
		return ;
	i = 0;
	while (str[i] && i < readed)
	{
		new->content[i] = str[i];
		i++;
	}
	new->content[i] = 0;
	if (!*buf)
	{
		*buf = new;
		return ;
	}
	last = ft_getlast(*buf);
	last->next = new;
}

void	get_line_appart(t_list *buf, char **str)
{
	int	i;
	int	j;

	if (!buf)
		return ;
	line_gen(str, buf);
	if (!(*str))
		return ;
	j = 0;
	while (buf)
	{
		i = 0;
		while (buf->content[i])
		{
			if (buf->content[i] == '\n')
			{
				(*str)[j++] = buf->content[i];
				break ;
			}
			(*str)[j++] = buf->content[i++];
		}
		buf = buf->next;
	}
	(*str)[j] = 0;
}

