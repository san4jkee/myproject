#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum response_type {DUMP, SECOND_CHANCE, MARRIAGE, LAW_SUIT};
typedef struct {
	char *name;
	enum response_type type;
} response;

void dump(response r)
{
	printf("Дорогой %s,\n", r.name);
	puts("К сожалению, Ваш недавний партнер по свиданию связался с нами,");
	puts("чтобы сообщить, что Вы с ним больше не увидитесь");
}

void second_chance(response r)
{
	printf("Дорогой %s,\n", r.name);
        puts("Хорошие новости: Ваш недавний партнер по свиданию попросил нас");
        puts("организовать еще одну встречу. Пожалуйста, перезвоните как можно скорее");
}

void marriage(response r)
{
	printf("Дорогой %s,\n", r.name);
        puts("Поздравляем! Ваш недавний партнер по свиданию");
        puts("связался с нами с предложением о браке.");
}
void law_suit(response r)
{
	printf("Дорогой %s,\n", r.name);
        puts("Поздравляем! Ваш недавний партнер по свиданию");
        puts("влюбился в Вас.");
}

void (*replies[])(response) = {dump, second_chance, marriage, law_suit};

int	main()
{
	response r[] = {
		{"Майк", DUMP}, {"Луис", SECOND_CHANCE},
		{"Мэттью", SECOND_CHANCE}, {"Уильям", MARRIAGE},
		{"Бред", LAW_SUIT}, {"ВиллиВонка", LAW_SUIT}
	};
	int i;
	for (i = 0; i < 6; i++)
	{
		(replies[r[i].type])(r[i]);
	}
	return 0;
}
