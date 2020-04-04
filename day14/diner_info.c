#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int	main(int argc, char *argv[])
{
	printf("Обедов: %s\n", argv[1]);
	printf("Сок: %s\n", getenv("JUICE"));
	return 0;
	char *my_env[] = {"JUICE=персик и яблоко", NULL};
        execle("diner_info", "diner_info", "4", NULL, my_env);
        puts(strerror(errno));

}
