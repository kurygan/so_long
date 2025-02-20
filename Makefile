CC = cc
FLAGS = -Wall -Wextra -Werror

MLXPATH = ./MLX42
MLXHEAD = $(MLXPATH)/include
MLXLIB = $(MLXPATH)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS = so_long.c utils.c \
	   map_format.c \

OBJS = $(SRCS:.c=.o)
SRCS_DIR = src/
OBJS_DIR = build/
SRCS_PREF = $(addprefix $(SRCS_DIR), $(SRCS))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS))

NAME = so_long

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -g -c $< -o $@

$(NAME): $(OBJS_PREF) signature
	@$(CC) $(FLAGS) $(OBJS_PREF) $(MLXLIB) -g -o $(NAME)
	@echo "|🛠️| Program Compiled"

all: libmlx $(NAME)

libmlx:
	@cmake $(MLXPATH) -B $(MLXPATH)/build && make -C $(MLXPATH)/build -j4
	@echo "|📚| MLX Compiled"

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