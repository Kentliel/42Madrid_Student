NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
INCLUDES = -I includes

SRC_DIR = srcs
OBJ_DIR = objs

SRCS = $(SRC_DIR)/main.c \
		$(SRC_DIR)/actions/actions.c \
		$(SRC_DIR)/cleanup/cleanup.c \
		$(SRC_DIR)/init/init.c \
		$(SRC_DIR)/monitor/monitor.c \
		$(SRC_DIR)/parse/parse.c \
		$(SRC_DIR)/routine/routine.c \
		$(SRC_DIR)/time/time.c \
		$(SRC_DIR)/utils/utils.c

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
