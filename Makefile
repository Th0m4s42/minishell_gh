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
SIGNALS	:= signals/
UTILS	:= utils/
OBJ_DIR	:= objs/

SRCS := \
	$(SRC_DIR)minishell.c \
	\
	$(SRC_DIR)$(ENV)env.c \
	$(SRC_DIR)$(ENV)list_env_manip.c \
	\
	$(SRC_DIR)$(LEXER)token.c\
	$(SRC_DIR)$(LEXER)tab_token_utils.c\
	\
	$(SRC_DIR)$(PROMPT)prompt.c \

INCLUDES := -I includes

OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)/$(ENV)
	@mkdir -p $(OBJ_DIR)/$(EXEC)
	@mkdir -p $(OBJ_DIR)/$(LEXER)
	@mkdir -p $(OBJ_DIR)/$(PARSING)
	@mkdir -p $(OBJ_DIR)/$(PROMPT)
	@mkdir -p $(OBJ_DIR)/$(SIGNALS)
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "$(Cyan)Compiling $<...$(White)"

$(NAME) : $(OBJS)
	make -C libft/
	@$(CC) $(FLAGS) $(INCLUDES) libft/libft.a $(OBJS) -o $(NAME) -lreadline -Llibft -l:libft.a
	@echo "$(Green)$(NAME) CREATED $(White)"

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