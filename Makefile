NAME = pipex

CFLAGS = 

CC = cc 

SRCS = $(shell find srcs -name "*.c")

OBJS = $(SRCS:.c=.o)

DEPS = $(shell find includes -name "*.h") Makefile

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o pipex

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf pipex

re : fclean all

.PHONY : all re clean all