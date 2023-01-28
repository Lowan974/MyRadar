##
## EPITECH PROJECT, 2022
## B-MUL-100-LYN-1-1-myradar-lowan.ferraro
## File description:
## Makefile
##

SRC = $(shell find ./src -type f -name '*.c')

OBJ = $(SRC:.c=.o)

NAME = my_radar

all: $(NAME)

$(NAME):
	@gcc $(SRC) -o $(NAME) -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
