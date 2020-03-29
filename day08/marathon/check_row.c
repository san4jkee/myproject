int     check_row(char **tab, int y, int n)
{
       int i;

       i = 0;
       while (i < 9)
       {
           if (tab[y][i] == n + '0')
               return (0);
           i++;
       }
       return (1);
}

int     check_column(char **tab, int x, int n)
{
       int j;

       j = 0;
       while (j < 9)
       {
           if (tab[j][x] == n + '0')
               return (0);
           j++;
       }
       return (1);
}

int     check_square(char **tab, int x, int y, int n)
{
       int i;
       int j;

       i = (x / 3) * 3;
       while (i < (x / 3) * 3 + 3)
       {
           j = (y / 3) * 3;
           while (j < (y / 3) * 3 + 3)
           {
               if (tab[j][i] == n + '0')
                   return (0);
               j++;
           }
           i++;
       }
       return (1);
}

int     solve(char **tab, int x, int y)
{
       int n;

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
                   if (solve(tab, (x + 1) % 9, y + ((x + 1) / 9)))
                       return (1);
               }
               n++;
           }
           tab[y][x] = '.';
           return (0);
       }
       else
           return (solve(tab, (x + 1) % 9, y + ((x + 1) / 9)));
}
