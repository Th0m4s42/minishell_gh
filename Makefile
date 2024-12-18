NAME	:= minishell
CC		:= cc
FLAGS	:= -Wall -Werror -Wextra -g

Black	:=\033[0;30m
Red		:=\033[0;31m
Green	:=\033[0;32m
Yellow	:=\033[0;33m
Blue	:=\033[0;34m
Purple	:=\033[0;35m
Cyan	:=\033[0;36m
White	:=\033[0;37m

SRC_DIR	:= srcs/
ENV		:= env/
EXEC	:= exec/
LEXER	:= lexer/
PARSING := parsing/
PROMPT	:= prompt/
SIGNALS	:= signal/
UTILS	:= utils/
EXEC	:= exec/
BUILTIN := builtin/
OBJ_DIR	:= objs/

SRCS := \
	$(SRC_DIR)minishell.c \
	\
	$(SRC_DIR)$(ENV)env.c \
	$(SRC_DIR)$(ENV)list_env_manip.c \
	\
	$(SRC_DIR)$(LEXER)token.c \
	$(SRC_DIR)$(LEXER)tab_token_utils.c \
	$(SRC_DIR)$(LEXER)lexer.c \
	$(SRC_DIR)$(LEXER)list_lex_manip.c \
	$(SRC_DIR)$(LEXER)check_cmds.c \
	$(SRC_DIR)$(LEXER)check_redirections.c \
	$(SRC_DIR)$(LEXER)init_function_array.c \
	$(SRC_DIR)$(LEXER)handle_errors.c \
	\
	$(SRC_DIR)$(SIGNALS)signal.c \
	\
	$(SRC_DIR)$(PROMPT)prompt.c \
	$(SRC_DIR)$(EXEC)exec.c \
	$(SRC_DIR)$(EXEC)exc_utils.c \
	$(SRC_DIR)$(EXEC)exec_cmd.c \
	$(SRC_DIR)$(EXEC)redirs.c \
	$(SRC_DIR)$(EXEC)shell_utils.c \
	$(SRC_DIR)$(EXEC)inits.c \
	$(SRC_DIR)$(BUILTIN)is_built_in.c \
	$(SRC_DIR)$(BUILTIN)exec_built_in.c \
	$(SRC_DIR)$(BUILTIN)var_utils.c \
	$(SRC_DIR)$(BUILTIN)ft_echo.c \
	$(SRC_DIR)$(BUILTIN)ft_pwd.c \
	$(SRC_DIR)$(BUILTIN)ft_cd.c \
	$(SRC_DIR)$(BUILTIN)ft_exit.c \
	$(SRC_DIR)$(BUILTIN)ft_env.c \
	$(SRC_DIR)$(BUILTIN)ft_export.c \
	$(SRC_DIR)$(BUILTIN)ft_unset.c \
	$(SRC_DIR)$(EXEC)here_doc.c \
	$(SRC_DIR)$(EXEC)here_doc_utils.c \
	# $(SRC_DIR)$(EXEC)pipe_n_utils.c \

INCLUDES := -I includes

OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)/$(ENV)
	@mkdir -p $(OBJ_DIR)/$(EXEC)
	@mkdir -p $(OBJ_DIR)/$(LEXER)
	@mkdir -p $(OBJ_DIR)/$(PARSING)
	@mkdir -p $(OBJ_DIR)/$(PROMPT)
	@mkdir -p $(OBJ_DIR)/$(SIGNALS)
	@mkdir -p $(OBJ_DIR)/$(EXEC)
	@mkdir -p $(OBJ_DIR)/$(BUILTIN)
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "$(Cyan)Compiling $<...$(White)"

$(NAME) : $(OBJS)
	make -C libft/
	@$(CC) $(FLAGS) $(INCLUDES) libft/libft.a $(OBJS) -o $(NAME) -lreadline -Llibft -l:libft.a
	@echo "$(Green)$(NAME) CREATED $(White)"
# -l:libft.a
	
all : $(NAME)

clean :
	@make -s -C libft/ clean
	@echo "$(Red)Cleaning object files...$(White)"
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make -s -C libft/ fclean
	@rm -f $(NAME)
	@echo "$(Red)$(NAME) DELETED $(White)"

re : fclean all

.PHONY: re clean fclean