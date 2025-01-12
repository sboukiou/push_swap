BUILDS=./build/0-main.c
SRCS=./srcs/*
LIBS=./build/libft.a
NAME=push_swap

$(NAME): $(BUILDS) $(SRCS) $(LIBS)
	$(CC) -o $(NAME) $(BUILDS) $(SRCS) $(LIBS)

clean:
	rm -f $(NAME)
