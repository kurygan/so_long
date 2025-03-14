/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 23:58:43 by mkettab           #+#    #+#             */
/*   Updated: 2025/03/14 23:58:45 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	malloc_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_handle(M_NOT_F);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), error_handle(EMPT_MAP), 0);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**get_map(char *file, t_map *map)
{
	int		fd;
	char	**temp;
	int		i;
	int		j;

	map->len.y = malloc_lines(file);
	temp = malloc(sizeof(char *) * (map->len.y + 1));
	if (!temp)
		exit(EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	i = -1;
	while (++i < map->len.y)
	{
		temp[i] = get_next_line(fd);
		if (!temp[i])
			return (freeall(temp), exit(EXIT_FAILURE), NULL);
		j = 0;
		while (temp[i][j] && temp[i][j] != '\n')
			j++;
		if (temp[i][j] && temp[i][j] == '\n')
			temp[i][j] = 0;
	}
	temp[i] = NULL;
	close(fd);
	return (temp);
}
