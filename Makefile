CC := cc
CFLAGS := -Wall -Wextra -Werror -g # -Ofast
DEBUG_FLAGS := -g -O0
NAME := minishell

# .h files
H_FILES := include/include.h

# .c files
vpath %.c src/base
vpath %.c src/expressions
vpath %.c src/token
vpath %.c src/builtins
vpath %.c src/env
vpath %.c src/exec
vpath %.c src/externals
vpath %.c src/utils
vpath %.c src/minishell

SRC_FILES := is_cmd.c main.c shell.c \
	create_expression.c expression_has_syntax_error.c free_expression.c parse_cmd_values.c parse_expression.c print_expression.c print_expression_type.c \
	create_token.c free_token.c get_closing_group.c is_operator.c parse_token.c print_token.c print_token_type.c token_has_syntax_error.c \
	execute_minishell.c free_minishell.c init_minishell.c \
	cd.c echo.c env.c exit.c export.c pwd.c unset.c \
	env_init.c env_utils.c \
	builtin.c execute.c \
	externals.c \
	fd.c \

# .o files
OBJ_DIR := obj
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# libft
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

# includes
INCLUDES := -I include -I libft
LIBS := $(LIBFT)
LDFLAGS := -L$(LIBFT_DIR) -lncurses -lreadline
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
