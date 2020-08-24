CC = gcc
NAME = rush-02
SRC = srcs/ft_putstr.c srcs/ft_print.c srcs/num2words.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_is_numeric.c srcs/ft_is_printable.c srcs/ft_is_space.c srcs/ft_putdicterror.c srcs/ft_puterror.c srcs/str_separate.c srcs/create_dict.c srcs/main.c srcs/num_check.c
OBJ = $(SRC:.c=.o)
CFLAG = -Wall -Wextra -Werror
INCLUDE = -I./includes

all: $(NAME)

.c.o:
	$(CC) $(CFLAG) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(INCLUDE) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
