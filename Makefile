NAME = pipex

CC = cc

SRCS = $(shell find srcs -name "*.c")

CFLAGS = -Wall -Wextra -Werror

DEPS = $(shell find includes -name "*.h") Makefile

all : $(NAME)

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) $(DEPS) 
	$(CC) -fsanitize=address $(CFLAGS) $(OBJS) -o $(NAME)

clean : 
	rm $(OBJS)

fclean : clean
	rm -rf pipex

re : fclean all

.PHONY : $(NAME) fclean all re clean