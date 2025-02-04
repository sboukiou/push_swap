NAME=push_swap

LIBFT_SRCS=./libft/ft_atoi.c  ./libft/ft_isdigit.c  ./libft/ft_memcmp.c\
./libft/ft_split.c  ./libft/ft_strlen.c  ./libft/ft_strncmp.c ./libft/ft_calloc.c ./libft/ft_strlcpy.c ./libft/ft_memset.c\

LIBFT_OBJS=./libft/ft_atoi.o  ./libft/ft_isdigit.o  ./libft/ft_memcmp.o\
./libft/ft_split.o  ./libft/ft_strlen.o  ./libft/ft_strncmp.o ./libft/ft_calloc.o ./libft/ft_strlcpy.o ./libft/ft_memset.o\


SHARED_SRCS=actions.c llist_tools_basic.c llist_tools_last.c parser.c llist_tools_more.c  simple_sorters.c sorter.c ref_utils.c advanced_actions.c
SHARED_OBJS= $(SHARED_SRCS:%.c=%.o)

MANDATORY_SRC=main.c
MANDATORY_OBJ=main.o

BONUS_SRC=main_bonus.c utils_bonus.c
BONUS_OBJS= $(BONUS_SRC:%.c=%.o)
BONUS=checker


CC=cc -Wall -Werror -Wextra -o
CO=cc -Wall -Werror -Wextra -c

%.o: %.c
	$(CO) $(CFLAGS) $< -o $@

$(NAME): $(SHARED_OBJS) $(LIBFT_OBJS) $(MANDATORY_OBJ)
	$(CC) $(NAME) $(SHARED_OBJS) $(LIBFT_OBJS) $(MANDATORY_OBJ)

all: $(NAME)

$(BONUS): $(BONUS_OBJS) $(LIBFT_SRCS) $(SHARED_OBJS) $(LIBFT_OBJS)
	$(CC) $(BONUS) $(SHARED_OBJS) $(LIBFT_OBJS) $(BONUS_OBJS)
bonus: $(BONUS)

clean:
	$(RM) $(SHARED_OBJS) $(BONUS_OBJS) $(MANDATORY_OBJ) $(LIBFT_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all
