NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes -I libft/includes

SRC_DIR = srcs
OBJ_DIR = objs

SRCS = $(SRC_DIR)/main.c \
	$(SRC_DIR)/utils/utils_file.c \
	$(SRC_DIR)/utils/utils_split.c \
	$(SRC_DIR)/parser/parser_main.c \
	$(SRC_DIR)/parser/parser_checks.c \
	$(SRC_DIR)/parser/parser_path.c

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) 
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅ Complete Compilation: $(NAME)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "📂 Created folder: $(OBJ_DIR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "🔨 Compiled: $<"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 Delete objects"

fclean:
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "🗑️ Removed binary"

re: fclean all

.PHONY: all clean fclean re
