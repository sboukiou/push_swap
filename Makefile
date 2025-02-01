
NAME=push_swap

LIBFT_SRCS=./libft/ft_atoi.c  ./libft/ft_isdigit.c  ./libft/ft_memcmp.c\
./libft/ft_split.c  ./libft/ft_strlen.c  ./libft/ft_strncmp.c ./libft/ft_calloc.c ./libft/ft_strlcpy.c ./libft/ft_memset.c\

SHARED_SRCS=actions.c llist_tools.c parser.c llist_tools_more.c  simple_sorters.c sorter.c

MANDATORY=main.c

GEN=gen
GEN_SOURCE=./generator.c

CC=cc -Wall -Werror -Wextra -o

$(NAME): ./*.c
	$(CC) $(NAME) $(SHARED_SRCS) $(LIBFT_SRCS) $(MANDATORY)

all: $(NAME)

gen:
	$(CC) $(GEN) $(GEN_SOURCE)

clean:
	$(RM) $(NAME) $(GEN)
