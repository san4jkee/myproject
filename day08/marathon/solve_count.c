int     solve_count(char **tab, int x, int y)
{
       int n;
       int count;
       count = 0;
       if (y >= 9 || x >= 9)
           return (1);
       if (tab[y][x] == '.')

       {

           n = 1;
           while (n < 10)
           {
               if (check_row(tab, y, n) && check_column(tab, x, n)
                   && check_square(tab, x, y, n))
               {
                   tab[y][x] = n + '0';
                   count += solve_count(tab, (x + 1) % 9, y + ((x + 1) / 9));
               }
               n++;
           }
           tab[y][x] = '.';
       return (count);


       }
       else
           return (solve_count(tab, (x + 1) % 9, y + ((x + 1) / 9)));
}
