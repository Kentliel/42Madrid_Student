NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
LIBFT = ./libft/libft.a
INCLUDES = -I./includes
# write the functions to be used in the library
SRCS = srcs/ft_printf.c \
	   srcs/ft_try_format.c \
	   srcs/ft_print_char.c \
	   srcs/ft_print_str.c \
	   srcs/ft_print_nbr.c \
	   srcs/ft_print_unsigned.c \
	   srcs/ft_print_hex.c \
	   srcs/ft_print_ptr.c

#Manual listing of the corresponding objects in the folder ‘objs’.
OBJS = objs/ft_printf.o \
	   objs/ft_try_format.o \
	   objs/ft_print_char.o \
	   objs/ft_print_str.o \
	   objs/ft_print_nbr.o \
	   objs/ft_print_unsigned.o \
	   objs/ft_print_hex.o \
	   objs/ft_print_ptr.o

all: $(NAME)

#The libft is compiled first with its bonus
$(LIBFT):
	$(MAKE) bonus -C libft

# Rule for creating the final library:
# First copy the compiled libft (which includes bonus)
# and then add with ar our objects
$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJS)
	rm -rf objs

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

#Pattern rule: compile from ‘srcs’ to ‘objs’.
objs/%.o: srcs/%.c
	@mkdir -p objs
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean fclean re
