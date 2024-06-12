CC = cc

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

SRCS = $(shell find srcs -name "*.c")

OBJS = $(SRCS:.c=.o)

DEPS = Makefile $(OBJS) $(shell find includes -name "*.h")

all: $(NAME)

$(NAME): $(DEPS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re