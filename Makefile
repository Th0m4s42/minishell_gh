NAME := minishell
CC := cc
FLAGS := -Wall -Werror -Wextra -g

Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

SRC_DIR := srcs/
OBJ_DIR := objs/

SRCS := \
	$(SRC_DIR)minishell.c \

INCLUDES := -I includes

OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
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