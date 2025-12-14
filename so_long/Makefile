NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes -I libft/includes -I minilibx-linux

SRC_DIR = srcs
OBJ_DIR = objs

SRCS = $(SRC_DIR)/main.c \
	$(SRC_DIR)/utils/utils_file.c \
	$(SRC_DIR)/utils/utils_split.c \
	$(SRC_DIR)/parser/parser_main.c \
	$(SRC_DIR)/parser/parser_checks.c \
	$(SRC_DIR)/parser/parser_path.c \
	$(SRC_DIR)/game/init_game.c \
	$(SRC_DIR)/game/render_map.c \
	$(SRC_DIR)/game/game_move.c \
	$(SRC_DIR)/game/game_images.c

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_LIB2 = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) 
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Complete Compilation: $(NAME)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "📂 Created folder: $(OBJ_DIR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "🔨 Compiled: $<"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "🧹 Delete objects"

fclean:
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(MLX_LIB)
	@rm -f $(MLX_LIB2)
	@echo "🗑️ Removed binary and libraries"

re: fclean all

.PHONY: all clean fclean re
