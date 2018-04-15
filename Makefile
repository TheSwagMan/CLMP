FLAGS = -W -Wall -Wextra -Werror -g
MAIN = monopoly.c
PARTS = gui.c structures.c utils.c
MAINO = $(MAIN:.c=.o)
OBJS = $(PARTS:.c=.o)  
CC = gcc

NAME = clmp

all: $(NAME)

re: fclean all

$(NAME): $(OBJS) $(MAINO)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c %.h
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -fr $(OBJS) $(MAINO)

fclean: clean
	rm -fr $(NAME)

