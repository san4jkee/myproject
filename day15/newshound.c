#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

int	main(int argc, char *argv[])
{
	char *phrase = argv[1];
	char *vars[] = {"RSS_FEED=https://www.kommersant.ru/RSS/news.xml", NULL};
	FILE *f = fopen("stories.txt", "w");
	if (!f) {
		error("не могу открыть stories.txt");
	}
	pid_t pid = fork();
	if (pid == -1) {
		error("не могу клонировать процесс");
	}
	if (!pid) {
		if (dup2(fileno(f),1) == -1) {
			error("не могу перенаправить стандартный вывод");
		}
		if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1) {
			error("не могу запустить скрипт");
		}
	}
	int pid_status;
	if (waitpid(pid, &pid_status,  0) == -1) {
		error("Ошибка во время ожидания дочернего процесса");
	}

	int fd[2];
	if (pipe(fd) == -1) {
		error("Не могу создать канал");
	}
	return 0;
}
