NAME := libft.a
CC := cc
FLAGS := -Wall -Werror -Wextra

Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

SRC_DIR := src/
OBJ_DIR := obj/
SRCS := \
	$(SRC_DIR)src_libft/ft_isalpha.c \
	$(SRC_DIR)src_libft/ft_isdigit.c \
	$(SRC_DIR)src_libft/ft_isalnum.c \
	$(SRC_DIR)src_libft/ft_isascii.c \
	$(SRC_DIR)src_libft/ft_isprint.c \
	$(SRC_DIR)src_libft/ft_strlen.c \
	$(SRC_DIR)src_libft/ft_memset.c \
	$(SRC_DIR)src_libft/ft_bzero.c \
	$(SRC_DIR)src_libft/ft_memcpy.c \
	$(SRC_DIR)src_libft/ft_memmove.c \
	$(SRC_DIR)src_libft/ft_strlcpy.c \
	$(SRC_DIR)src_libft/ft_strlcat.c \
	$(SRC_DIR)src_libft/ft_toupper.c \
	$(SRC_DIR)src_libft/ft_tolower.c \
	$(SRC_DIR)src_libft/ft_strchr.c \
	$(SRC_DIR)src_libft/ft_strrchr.c \
	$(SRC_DIR)src_libft/ft_strncmp.c \
	$(SRC_DIR)src_libft/ft_memchr.c \
	$(SRC_DIR)src_libft/ft_memcmp.c \
	$(SRC_DIR)src_libft/ft_strnstr.c \
	$(SRC_DIR)src_libft/ft_atoi.c \
	$(SRC_DIR)src_libft/ft_calloc.c \
	$(SRC_DIR)src_libft/ft_strdup.c \
	$(SRC_DIR)src_libft/ft_substr.c \
	$(SRC_DIR)src_libft/ft_strjoin.c \
	$(SRC_DIR)src_libft/ft_strtrim.c \
	$(SRC_DIR)src_libft/ft_split.c \
	$(SRC_DIR)src_libft/ft_itoa.c \
	$(SRC_DIR)src_libft/ft_strmapi.c \
	$(SRC_DIR)src_libft/ft_striteri.c \
	$(SRC_DIR)src_libft/ft_putchar_fd.c \
	$(SRC_DIR)src_libft/ft_putstr_fd.c \
	$(SRC_DIR)src_libft/ft_putendl_fd.c \
	$(SRC_DIR)src_libft/ft_putnbr_fd.c \
	$(SRC_DIR)src_libft/ft_lstadd_back.c \
	$(SRC_DIR)src_libft/ft_lstadd_front.c \
	$(SRC_DIR)src_libft/ft_lstclear.c \
	$(SRC_DIR)src_libft/ft_lstdelone.c \
	$(SRC_DIR)src_libft/ft_lstiter.c \
	$(SRC_DIR)src_libft/ft_lstlast.c \
	$(SRC_DIR)src_libft/ft_lstmap.c \
	$(SRC_DIR)src_libft/ft_lstnew.c \
	$(SRC_DIR)src_libft/ft_lstsize.c \
	\
	$(SRC_DIR)src_ft_printf/ft_printchar.c \
	$(SRC_DIR)src_ft_printf/ft_printf.c \
	$(SRC_DIR)src_ft_printf/ft_printhex.c \
	$(SRC_DIR)src_ft_printf/ft_printnbr.c \
	$(SRC_DIR)src_ft_printf/ft_printptr.c \
	$(SRC_DIR)src_ft_printf/ft_printstr.c \
	$(SRC_DIR)src_ft_printf/ft_printunbr.c \
	\
	$(SRC_DIR)src_get_next_line/get_next_line.c \
	\

INCLUDES := -I includes

OBJS := $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "$(Cyan)Compiling $<...$(White)"

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)
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
