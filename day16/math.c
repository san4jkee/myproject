#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;
int a = 0;
int b = 0;

void end_game(int sig)
{
	printf("\nИтоговый счет : %i\n", score);
	exit(0);
}

int catch_signal(int sig, void (*handler)(int))
{
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	return sigaction (sig, &action, NULL);
}

void times_up(int sig)
{
	puts("\nВРЕМЯ ВЫШЛО!");
	raise(SIGINT);
}

void error(char *msg)
{
	printf("\nСколько будет %i умножить на %i? ", a, b);
	exit(1);
}

int	main()
{
	catch_signal(SIGALRM, times_up);
	catch_signal(SIGINT, end_game);
	srandom (time (0));
	while (1) {
		int a = random() % 11;
		int b = random() % 11;
		char txt[4];
		alarm(5);
		printf("\nСколько будет  %i умножить на %i? ", a, b);
		fgets(txt, 4, stdin);
		int answer = atoi(txt);
		if (answer == a * b)
			score++;
		else
			printf("\nНеправильно! Счет: %i\n", score);
	}
	return 0;
}
