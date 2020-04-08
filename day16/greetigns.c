#include <stdio.h>

int	main()
{
	char name[30];
	printf("Введите свое имя: ");
	fgets(name, 30, stdin);
	printf("Привет %s\n", name);
	return 0;
}
