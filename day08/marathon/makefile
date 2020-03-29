NAME = libft.a

SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_putnbr.c

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) ft_putchar.o ft_putstr.o ft_putnbr.o
	ranlib $(NAME)

clean:
	/bin/rm -f ft_putchar.o ft_putstr.o ft_putnbr.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

main.o: main.c
	gcc -c -o main.o main.c

check_row.o: check_row.c
	gcc -c -o check_row.o check_row.c

solve_count.o: solve_count.c
	gcc -c -o solve_count.o solve_count.c

sudoku: main.o check_row.o solve_count.o
	gcc -Wall -Werror -Wextra -o sudoku main.o check_row.o solve_count.o
