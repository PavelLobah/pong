CC = gcc -Wall -Werror -Wextra -lncurses
NAME = pong

all: clean
	$(CC) $(NAME).c -o $(NAME)
	./$(NAME)

clean: 
	rm -rf $(NAME) *.o *.out

git:
	git add .
	git commit -m "$(DATE)"
	git push origin master