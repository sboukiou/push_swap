
NAME=push_swap
CC=cc

$(NAME): ./*.c
	$(CC) -o $(NAME) ./libft/*.c ./*.c
all: $(NAME)
