CC = gcc -Wall -Werror -Wextra -lncurses
NAME = pong
DATE = $(shell date -R)

all: clean
	$(CC) $(NAME).c -o $(NAME)
	./$(NAME)

clean: 
	rm -rf $(NAME) *.o *.out

git:
	git add .
	git commit -m "$(DATE)"
	git push origin master