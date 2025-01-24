CC := cc
CFLAGS := -Wall -Wextra -Werror # -Ofast
DEBUG_FLAGS := -g -O0
NAME := minishell

# .h files
H_FILES := include/include.h

# .c files
SRC_DIR := src/base
vpath %.c $(SRC_DIR)
SRC_FILES := main.c

# .o files
OBJ_DIR := obj
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(BASE_SRC_FILES:.c=.o))

# libft
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

# includes
INCLUDES := -I include -I libft
LIBS := $(LIBFT)
LDFLAGS := -L$(LIBFT_DIR)
LDLIBS := -lft

# all
all: $(NAME)

# bonus
bonus: $(NAME)

# Link
$(NAME): $(LIBS) $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LDFLAGS) $(LDLIBS) -o $(NAME)

# Compile obj
$(OBJ_DIR)/%.o: %.c $(H_FILES) $(LIBFT) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# clean
clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

# fclean
fclean:
	$(RM) -rf $(OBJ_DIR)
	$(RM) -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# re
re: fclean all

# debug
debug: CFLAGS += $(DEBUG_FLAGS)
debug: re bonus

.PHONY: all clean fclean re debug bonus
