SRC_FILE = src/so_long.c src/so_long_utils.c src/handl_error.c src/handl_error_utils.c\
			src/put_image.c src/evente.c g_n_l/get_next_line.c g_n_l/get_next_line_utils.c

SRC_FILE_BONUS = src_bonus/so_long_bonus.c src_bonus/so_long_utils_bonus.c src_bonus/handl_error_bonus.c src_bonus/handl_error_utils_bonus.c\
			src_bonus/put_image_bonus.c src_bonus/evente_bonus.c src_bonus/animation_bonus.c \
				g_n_l/get_next_line.c g_n_l/get_next_line_utils.c

NAME = so_long
NAME_BONUS = so_long_bonus
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJ_FILE_BONUS = $(SRC_FILE_BONUS:.c=.o)
HEADER = so_long.h so_long_bonus.h
CC = cc
RM = rm -rf

MLX_DIR = ./minilibx_opengl_20191021
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

CFLAGS = -I$(MLX_DIR) -Wall -Wextra -Werror

PURPLE = \033[0;35m
BLUE = \033[0;34m
RED = \033[0;31m

LIBTF_PATH = ./libft
LIBFT = $(LIBTF_PATH)/libft.a

all : libft $(NAME) LIBFT

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILE)
	@$(CC) $(CFLAGS) $(OBJ_FILE) -o $(NAME) $(MLX_FLAGS) $(LIBFT)

bonus : libft $(OBJ_FILE_BONUS) LIBFT
	@$(CC) $(CFLAGS) $(OBJ_FILE_BONUS) -o $(NAME_BONUS) $(MLX_FLAGS) $(LIBFT)

libft:
	@make -C $(LIBTF_PATH) --silent

clean :
	@$(RM) $(OBJ_FILE) $(OBJ_FILE_BONUS)
	@make -C $(LIBTF_PATH) clean
	@echo "$(RED) TOUT EST CLEAR"

fclean : clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make -C $(LIBTF_PATH) fclean

re : fclean all

.PHONY: libft 