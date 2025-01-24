CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address
NAME = libft.a

# libft
LIBFT_H_FILE := libft/libft.h
LIBFT_SRC_FILES := ft_abs.c ft_aish.c ft_aisi.c ft_atocolor.c ft_atoi.c ft_bzero.c ft_calloc.c ft_free_ints.c ft_free_strs.c ft_htoi.c ft_in_charset.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_max.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_min.c ft_print_strs.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_remove_charackter.c ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_printstr_fd.c ft_write_bytes.c
vpath %c libft

# ft_printf 
PRINTF_H_FILE := ft_printf/include/ft_printf.h
PRINTF_SRC_FILES := ft_print_c.c ft_print_i.c ft_print_l.c ft_print_p.c ft_print_per.c ft_print_s.c ft_print_u.c ft_print_x.c ft_print_xx.c ft_printf.c
vpath %c ft_printf/srcs

# get next line  
GET_NEXT_LINE_H_FILE := get_next_line/get_next_line.h
GET_NEXT_LINE_SRC_FILES := get_next_line.c get_next_line_utils.c
vpath %c get_next_line

OBJ_DIR := obj
SRC_FILES := $(LIBFT_SRC_FILES) $(PRINTF_SRC_FILES) $(GET_NEXT_LINE_SRC_FILES)
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
H_FILES := $(LIBFT_H_FILE) $(PRINTF_H_FILE) $(GET_NEXT_LINE_H_FILE)
INCLUDES := -Ilibft -Ift_printf/include -Iget_next_line

# All
all: $(NAME)

# Regular Objs
$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

# Compile OBJ_FILES
$(OBJ_DIR)/%.o: %.c $(H_FILES) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean
clean:
	@echo "Cleaning libft"
	rm -rf $(OBJ_DIR)

# Fclean
fclean:
	@echo "Fcleaning libft"
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

# Re
re: fclean all

.PHONY: all clean fclean re
