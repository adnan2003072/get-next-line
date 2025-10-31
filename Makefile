NAME = libgnl.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lbsd
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: re main.c  $(NAME)
	$(CC) main.c -lbsd -L. -lgnl && ./a.out
