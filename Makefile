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
OBJ_DIR	:= objs/

SRCS := \
	$(SRC_DIR)minishell.c \
	\
	$(SRC_DIR)$(ENV)env.c\
	\
	\
	$(SRC_DIR)ft_split.c \
	\

INCLUDES := -I includes

OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)/$(ENV)%.c
	@mkdir -p $(OBJ_DIR)/$(EXEC)%.c
	@mkdir -p $(OBJ_DIR)/$(LEXER)%.c
	@mkdir -p $(OBJ_DIR)/$(PARSING)%.c
	@mkdir -p $(OBJ_DIR)/$(PROMPT)%.c
	@mkdir -p $(OBJ_DIR)/$(SIGNALS)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $< -MD
	@echo "$(Cyan)Compiling $<...$(White)"

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME) -lreadline
	@echo "$(Green)$(NAME) CREATED $(White)"

all : $(NAME)

clean :
	@echo "$(Red)Cleaning object files...$(White)"
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)
	@echo "$(Red)$(NAME) DELETED $(White)"

re : fclean all

.PHONY: re clean fclean