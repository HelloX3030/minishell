CC := cc
CFLAGS := -Wall -Wextra -Werror
DEBUG_FLAGS := -g -O0
NAME := minishell
DEBUG_NAME := minishell_debug

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
vpath %.c src/redirections

SRC_FILES := is_cmd.c main.c shell.c \
	create_expression.c expression_has_syntax_error.c free_expression.c parse_cmd_values.c parse_expression.c print_expression.c print_expression_type.c \
	create_token.c free_token.c get_closing_group.c is_operator.c parse_token.c print_token.c print_token_type.c token_has_syntax_error.c \
	execute_minishell.c exit_minishell.c free_minishell.c init_minishell.c \
	create_redir.c free_redir.c make_redir.c print_redir.c redirect.c reset_redirect.c restore_fd.c save_fd.c \
	cd.c echo.c env.c export.c pwd.c unset.c \
	env_init.c env_utils.c \
	builtin.c execute.c \
	externals.c \
	fd.c

# Normal .o files
OBJ_DIR := obj
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Debug .o files
OBJ_DEBUG_DIR := obj_debug
OBJ_DEBUG_FILES := $(addprefix $(OBJ_DEBUG_DIR)/, $(SRC_FILES:.c=.o))

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

#bonus
bonus: all

# Link normal executable
$(NAME): $(LIBS) $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LDFLAGS) $(LDLIBS) -o $(NAME)

# Compile normal obj files
$(OBJ_DIR)/%.o: %.c $(H_FILES) $(LIBFT) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile debug obj files
$(OBJ_DEBUG_DIR)/%.o: %.c $(H_FILES) $(LIBFT) | $(OBJ_DEBUG_DIR)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR) $(OBJ_DEBUG_DIR):
	mkdir -p $@

# Debug executable
debug: $(LIBFT) $(OBJ_DEBUG_FILES)
	$(CC) $(OBJ_DEBUG_FILES) $(LDFLAGS) $(LDLIBS) -o $(DEBUG_NAME)

# libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# clean
clean:
	$(RM) -r $(OBJ_DIR) $(OBJ_DEBUG_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

# fclean
fclean:
	$(RM) -rf $(OBJ_DIR)
	$(RM) -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# re
re: fclean all

# debug_clean
debug_clean:
	$(RM) -r $(OBJ_DEBUG_DIR)

# debug_fclean
debug_fclean:
	$(RM) -rf $(OBJ_DEBUG_DIR)
	$(RM) -f $(DEBUG_NAME)

# debug_re
debug_re: debug_fclean debug

# clean_all
clean_all: clean debug_clean

# fclean_all
fclean_all: fclean debug_fclean

# re_all
re_all: fclean_all all debug

.PHONY: all bonus clean fclean re debug debug_clean debug_fclean debug_re clean_all fclean_all re_all
