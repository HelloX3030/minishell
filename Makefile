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
vpath %.c src/signals
vpath %.c src/expansions

SRC_FILES := main.c shell.c get_input.c \
	get_expression_error.c create_expression.c expand_expr_vars.c get_token_unmatched_quotes.c free_expression.c parse_cmd_values.c parse_expression.c print_expression.c print_expression_type.c \
	create_token.c free_token.c get_closing_group.c is_operator.c parse_token.c print_token.c print_token_type.c \
	execute_minishell.c free_minishell.c init_minishell.c \
	create_redir.c free_redir.c make_redir.c print_redir.c redirect.c reset_redirect.c restore_fd.c save_fd.c  heredoc.c\
	cd.c echo.c env.c export.c pwd.c unset.c exit.c \
	env_init.c env_utils.c env_utils2.c pipes.c builtin_utils.c \
	builtin.c execute.c \
	externals.c externals2.c \
	list_to_arr.c print_quote_type.c remove_quotes.c \
	signals.c sigint.c \
	expand_env.c expand_wildcards.c expansion_utils.c get_matching_filenames.c \

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
	$(RM) -rf $(OBJ_DIR) $(OBJ_DEBUG_DIR)
	$(RM) -f $(NAME) $(DEBUG_NAME)
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

# run
run: all
	./$(NAME)

.PHONY: all bonus clean fclean re debug debug_clean debug_fclean debug_re run
