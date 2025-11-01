NAME = libgnl.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lbsd
MSRCS = get_next_line.c get_next_line_utils.c
BSRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
MOBJS = $(MSRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(MOBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(MOBJS) $(BOBJS)
	ar rcs $(NAME) $^

clean:
	$(RM) $(MOBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: re main.c $(NAME)
	$(CC) main.c -lbsd -L. -lgnl
	$(RM) $(MOBJS) $(BOBJS)
	./a.out
