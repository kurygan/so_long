CC = cc
FLAGS = -Wall -Wextra -Werror -g3

MLXPATH = ./MLX42
MLXHEAD = $(MLXPATH)/include
MLXLIB = $(MLXPATH)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS = so_long.c utils.c \
	   map_format.c \
	   error_handle.c \
	   get_next_line.c get_next_line_utils.c lst_clean.c \
	   assign_map.c parsing.c verif_walls.c verif_stats.c check_path.c\
	   init_and_display.c moves.c\
	   ft_memset.c

OBJS = $(SRCS:.c=.o)
SRCS_DIR = src/
OBJS_DIR = build/
SRCS_PREF = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS))

NAME = so_long

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS_PREF) $(MLXPATH)/build/libmlx42.a
	@cc $(FLAGS) $(OBJS_PREF) $(MLXLIB) -g -o $(NAME)
	@echo "Program compiled"

all: $(NAME)

libmlx: $(MLXFOLDER)/build/libmlx42.a

$(MLXFOLDER)/build/libmlx42.a:
	@cmake $(MLXFOLDER) -B $(MLXFOLDER)/build
	@make -C $(MLXFOLDER)/build -j4
	@echo "MLX Compiled"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "|🗑️| Removing objects.."

fclean: clean signature
	@rm -f $(NAME)
	@echo "|🧹| Cleaning.."

re: fclean all signature

.PHONY: all clean fclean re

signature:
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo "        ,====,,'''',,,             _____________________________________"
	@echo " _______||__||_______ ''',       /'                                    |"
	@echo "|    | |      | |    |    ;    /'  Name: ____Kurygan (mkettab)________ |"
	@echo "|   CMIYGL    | |    |   ;   / o   Address: __mkettab@student.42.fr___ |"
	@echo "|    | |      | |    |    '''\     School: ______42_Mulhouse__________ |"
	@echo "|    | |      IGOR   |        \`\          __CALL_ME_IF_YOU_GET_LOST___ |"
	@echo "|  OFWGKTA    | |    |          \`\.____________________________________|"
	@echo "|____|_|______|_|____|"
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""