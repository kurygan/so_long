/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:05:24 by mkettab           #+#    #+#             */
/*   Updated: 2025/03/05 03:46:35 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define E_FORMAT_MAP "Map format is wrong, you dumb shit!"
# define BUFFER_SIZE 5

// Error type
typedef enum s_error_handle
{
	wrong_args,
	map_format,
	map_nf,
	texture_nf,
	map_n_rect,
	map_walls,
	player
}					t_error_handle;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_map
{
	char			**map;
	int				count_c;
	int				p_base_x;
	int				p_base_y;
	int				y_len;
	int				x_len;
}					t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	int				pos_y;
	int				pos_x;
	int				curr_c;
	unsigned long	move_count;
	mlx_image_t		*player;
	mlx_image_t		*collectible;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*exit;
}					t_game;

void				ft_putstr_fd(char *str, int fd);
int					ft_strlen(char *str);
bool				verify_format(char *str);
int					ft_strrcmp(char *s1, char *s2);
char				**get_map(char *file, t_map *map);
void				verify_map(t_map *map, t_game *game);
void				verif_char(char **map);
void				verif_lenght(t_map *map);
void				verif_walls(char **map);
void				verif_up_down(char *temp, char **map);
void				*ft_memset(void *b, int c, size_t len);
void				ft_freeall(char **map);
void				error_handle(char *error);
void				verif_get_stats(t_map *map);
void				verif_player(t_map *map);
void				verif_exit(t_map *map);
void				count_coins(t_map *map);
void				check_path(t_map *map);
char				*ft_strdup(const char *s);
void				init_and_display(t_game *game, t_map *map);
void				init_textures(t_game *game);
mlx_image_t			*init_img(char *path, t_game *game);

//GNL functions
char				*get_next_line(int fd);
t_list				*ft_getlast(t_list *list);
int					ft_foundline(t_list *list);
int					read_and_stock(t_list **buf, int fd);
void				lst_clean(t_list **buf);
void				get_line_appart(t_list *buf, char **str);
void				stock_add(char *str, t_list **buf, int readed);
void				line_gen(char **str, t_list *buf);
void				lst_free(t_list *lst);
void				lst_clean_v2(t_list *get_last, t_list **buf, int *i);

#endif