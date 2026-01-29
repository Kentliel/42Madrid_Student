NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes -I libft/includes

SRC_DIR = srcs
OBJ_DIR = objs

SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/parsing/parse_args.c \
		$(SRC_DIR)/parsing/parse_utils.c \
		$(SRC_DIR)/stack/stack_new.c \
		$(SRC_DIR)/stack/stack_utils.c \
		$(SRC_DIR)/operations/swap.c \
		$(SRC_DIR)/operations/push.c \
		$(SRC_DIR)/operations/rotate.c \
		$(SRC_DIR)/operations/reverse_rotate.c \
		$(SRC_DIR)/sort/index_stack.c\
		$(SRC_DIR)/sort/sort_small.c \
		$(SRC_DIR)/sort/radix_sort.c 

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
