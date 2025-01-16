BUILDS=./build/0-main.c
SRCS=./srcs/*
LIBS=./libft/*.c
NAME=push_swap
CC=cc -Wall -Werror -Wextra

$(NAME): $(BUILDS) $(SRCS) $(LIBS)
	$(CC) -o $(NAME) $(LIBS) $(BUILDS) $(SRCS) 

clean:
	rm -f $(NAME)
