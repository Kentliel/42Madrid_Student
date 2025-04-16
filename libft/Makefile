#Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
# to create the static library
AR = ar rcs
SRCS = ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c

# Se descomenta al momento hacer los bonus
# SRCS_BONUS = \

OBJS = $(SRCS:.c=.o)

# Se descomenta al momento de hacer los bonus
# OBJS_BONUS = $(SRCS_BONUS:.c=.o) \

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# se descomenta a la hora de hacer los bonus
# bonus: $(OBJS) $(OBJS_BONUS)
#	$(AR) $@ $^ \

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
