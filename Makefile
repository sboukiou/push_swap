
NAME=push_swap

LIBFT_SRCS=./libft/ft_atoi.c  ./libft/ft_isdigit.c  ./libft/ft_memcmp.c\
./libft/ft_split.c  ./libft/ft_strlen.c  ./libft/ft_strncmp.c ./libft/ft_calloc.c ./libft/ft_strlcpy.c ./libft/ft_memset.c\

SHARED_SRCS=actions.c llist_tools_basic.c llist_tools_last.c parser.c llist_tools_more.c  simple_sorters.c sorter.c ref_utils.c advanced_actions.c

MANDATORY=main.c
BONUS_SRC=main_bonus.c
BONUS=checker

GEN=gen
GEN_SOURCE=./generator.c

CC=cc -Wall -Werror -Wextra -o

$(NAME): $(SHARED_SRCS) $(LIBFT_SRCS) $(MANDATORY)
	$(CC) $(NAME) $(SHARED_SRCS) $(LIBFT_SRCS) $(MANDATORY)

all: $(NAME)

gen:
	$(CC) $(GEN) $(GEN_SOURCE)

clean:
	$(RM) $(NAME) $(GEN) $(BONUS)

fclean:
	$(RM) $(NAME) $(GEN) $(BONUS)

re: fclean all

bonus: $(BONUS_SRC) $(LIBFT_SRCS) $(SHARED_SRCS)
	$(CC) $(BONUS) $(SHARED_SRCS) $(LIBFT_SRCS) $(BONUS_SRC)

