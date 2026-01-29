NAME = libft.a
CC = cc
CFLAG = -Wall -Wextra -Werror
INCLUDES = -I includes
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
PRINTF_DIR = ft_printf

LIBFT_FILES = ft_bzero.c\
        ft_isalnum.c\
        ft_isalpha.c\
        ft_isascii.c\
        ft_isdigit.c\
        ft_isprint.c\
		ft_isspace.c\
        ft_memcpy.c\
        ft_memmove.c\
        ft_memset.c\
        ft_strlen.c\
        ft_strlcpy.c\
        ft_strlcat.c\
        ft_toupper.c\
        ft_tolower.c\
        ft_strchr.c\
        ft_strrchr.c\
        ft_strncmp.c\
        ft_memchr.c\
        ft_memcmp.c\
        ft_strnstr.c\
        ft_atoi.c\
        ft_calloc.c\
        ft_strdup.c\
        ft_substr.c\
        ft_strjoin.c\
        ft_strtrim.c\
        ft_split.c\
		ft_free_split.c\
        ft_itoa.c\
		ft_atol.c\
        ft_strmapi.c\
        ft_striteri.c\
        ft_putchar_fd.c\
        ft_putstr_fd.c\
        ft_putendl_fd.c\
        ft_putnbr_fd.c\
		ft_lstnew.c\
        ft_lstadd_front.c\
        ft_lstsize.c\
        ft_lstlast.c\
        ft_lstadd_back.c\
        ft_lstdelone.c\
        ft_lstclear.c\
        ft_lstiter.c\
        ft_lstmap.c

PRINTF_FILES = ft_printf.c\
			ft_try_format.c\
			ft_print_char.c\
			ft_print_str.c\
			ft_print_nbr.c\
			ft_print_unsigned.c\
			ft_print_hex.c\
			ft_print_ptr.c

SRCS_LIBFT = $(addprefix $(SRC_DIR)/$(LIBFT_DIR)/, $(LIBFT_FILES))
SRCS_PRINTF = $(addprefix $(SRC_DIR)/$(PRINTF_DIR)/, $(PRINTF_FILES))

OBJS_LIBFT = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS_LIBFT))
OBJS_PRINTF = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS_PRINTF))
OBJS = $(OBJS_LIBFT) $(OBJS_PRINTF)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Libreria $(NAME) creada on éxito!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: 
	@rm -rf $(OBJ_DIR)
	@echo "Carpeta de objetos ($(OBJ_DIR)) eliminada."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) eliminada."

re: fclean all

.PHONY: all clean fclean re
