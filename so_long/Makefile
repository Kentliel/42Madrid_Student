NAME = so_long
CC = cc
CFLAGS = Wall -Wextra -Werror
INCLUDES = -Iincludes

SRC_DIR = srcs
OBJ_DIR = objs

SRCS = $(SRC_DIR)/main.c \
	$(SRC_DIR)/parser.c \
	$(SRC_DIR)/utils.c

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) 
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Complete Compilation: $(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@$(CC) $(CFLAG) $(INCLUDES) -c $< -o $@
	@echo "Created folder: $(OBJ_DIR)"

clean:
	@rm -f $(OBJ_DIR)
	@echo "Delete objects"

fclean:
	@rm -f $(NAME)
	@echo "Removed binary"

re: fclean all

.PHONY: all clean fclean re
