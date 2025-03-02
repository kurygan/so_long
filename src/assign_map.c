/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:34:44 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/21 02:53:39by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	malloc_lines(char *file, t_map *map)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
        error_handle("404: Map not Found!");
	line = get_next_line(fd);
	if (!line)
		error_handle("Empty Map!");
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("%d\n", count);
	map->y_len = count;
	return (count);
}

char	**get_map(char *file, t_map *map)
{
	int		fd;
	int		lines_number;
	char	**temp;
	int		i;
	int j;
	
	lines_number = malloc_lines(file, map);
	temp = malloc(sizeof(char *) * (lines_number + 1));
	if (!temp)
		exit(EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	j = 0;
	i = 0;
	while (i < lines_number)
	{
		temp[i] = get_next_line(fd);
		while (temp[i][j] && temp[i][j] != '\n')
			j++;
		if (temp[i][j] == '\n')
			temp[i][j] = 0;
		i++;
	}
	temp[i] = NULL;
	close(fd);
	return (temp);
}