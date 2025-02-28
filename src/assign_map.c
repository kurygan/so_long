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

static int	malloc_lines(char *file)
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
		error_handle("File Empty!");
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**get_map(char *file)
{
	int		fd;
	int		lines_number;
	char	**map;
	int		i;
	
	lines_number = malloc_lines(file);
	map = malloc(sizeof(char *) * (lines_number + 1));
	if (!map)
		exit(EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < lines_number)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}