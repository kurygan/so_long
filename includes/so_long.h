/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:05:24 by mkettab           #+#    #+#             */
/*   Updated: 2025/03/12 02:37:31 by mkettab          ###   ########.fr       */
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
# define NOT_RECT "Bro don't know how to make a rectangle"
# define N_ALL_CHAR "Only 10CEP, bro forgor it :|"
# define ARGS "You can't put 1 argument ?????"
# define EXT ".ber, it's not that complicated"
# define MAP_SIZE "It's too big (that's what she said)"
# define M_NOT_F "404 Error: Map not found"
# define EMPT_MAP "Put at least a 1 in a map..."
# define P_NUMB "You think this is a coop game lmao"
# define E_NUMB "How tf can there be more than 1 exit ???"
# define C_NUMB "The game is too easy if there is no coins"
# define W_N_COMPLETE "This is not an open world"
# define C_N_REACH "Collectible not reachable"
# define E_N_REACH "Exit not reachable"
# define IMG_LOAD "Image does not exist"
# define P_DISP "Player cannot be displayed"
# define C_DISP "Coin cannot be displayed"
# define E_DISP "Exit cannot be displayed"
# define W_DISP "Wall cannot be displayed"
# define F_DISP "Floor cannot be displayed"
# define BUFFER_SIZE 5

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_map
{
	char			**map;
	int				count_c;
	t_point			p_coord;
	t_point			len;
}					t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	t_point			pos;
	int				curr_c;
	bool			exit_reached;
	t_point			p;
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
void				freeall(char **map);
void				error_handle(char *error);
void				verif_get_stats(t_map *map);
void				verif_player(t_map *map);
void				verif_exit(t_map *map);
void				count_coins(t_map *map);
void				check_path(t_map *map, t_game *game);
char				*ft_strdup(const char *s);
void				init_and_display(t_game *game, t_map *map);
void				freeimg(t_game *game);
void				ft_hook(mlx_key_data_t key, void *param);
void				putnbr(unsigned long nbr);

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