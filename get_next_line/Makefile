NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
INCLUDES = -I./includes

SRCS =	srcs/ft_get_next_line.c \
	srcs/ft_get_next_line_utils.c

OBJS =	objs/ft_get_next_line.o \
	objs/ft_get_next_line_utils.o

HEADERS = includes/get_next_line.h

BUFFER_SIZE ?= 42
CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)

all:  $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

objs/%.o:	srcs/%.c $(HEADERS)
		@mkdir -p objs
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf objs

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
