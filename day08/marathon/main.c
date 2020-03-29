#include <unistd.h>

int     solve(char **tab, int x, int y);
int     solve_count(char **tab, int x, int y);
void    ft_putchar(char c)
{
       write(1, &c, 1);
}

void    ft_putstr(char *str)
{
       int i;

       i = 0;
       while (*(str + i) != '\0')
       {
           ft_putchar(*(str + i));
           i++;
       }
}

void    ft_putnbr(int n)
{
       int     i;
       int     vect[20];
       long    nb;

       nb = n;
       i = -1;
       if (nb < 0)
       {
           ft_putchar('-');
           nb = -nb;
       }
       if (nb == 0)
           ft_putchar('0');
       while (nb > 0)
       {
           i++;
           vect[i] = nb % 10;
           nb = nb / 10;
       }
       while (i > -1)
       {
           ft_putchar('0' + vect[i]);
           i--;
       }
}

int     ft_check_input(int argc, char **argv)
{
       int i;
       int j;

       i = 1;
       j = 0;
       if (argc != 10)
           return (1);
       while (i < argc)
       {
           while (argv[i][j])
               j++;
           if (j != 9)
               return (1);
           j = 0;
           while (argv[i][j] == '.' || (argv[i][j] > '0' && argv[i][j] <= '9'))
               j++;
           if (j != 9)
               return (1);
           j = 0;
           i++;
       }
       if (i != 10)
           return (1);
       else
           return (0);
}

void    ft_print_sudoku(char **tab)
{
       int i;
       int j;

       i = 1;
       j = 0;
       while (i < 10)
       {
           while (j < 9)
           {
               ft_putchar(tab[i][j]);
               if (j < 8)
                   ft_putchar(' ');
               j++;
           }
           ft_putchar('\n');
           j = 0;
           i++;
       }
}

int     main(int argc, char **argv)
{
       if (ft_check_input(argc, argv))
           ft_putstr("Error: not a good sudoku\n");
       else
       {
           if (solve(argv + 1, 0, 0))
           {
               ft_print_sudoku(argv);
               ft_putnbr(solve_count(argv + 1, 0, 0));
           }
           else
               ft_putstr("Error: no solution\n");
       }
       return (0);
}
