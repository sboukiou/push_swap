NAME=libft.a

CC=cc
CFLAGS= -c -Wall -Werror -Wextra
AR=ar -rcs
RM=rm -f

MAN_SRCS=ft_atoi.c ft_bzero.c ft_calloc.c ft_isdigit.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c
MAN_OBJS := $(MAN_SRCS:%.c=%.o)

$(NAME): $(MAN_OBJS) 
	$(AR) $(NAME) $(MAN_OBJS)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean: 
	$(RM)  $(MAN_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean bonus
