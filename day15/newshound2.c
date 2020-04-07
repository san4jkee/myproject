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

void open_url(char *url)
{
	char launch[255];
	sprintf(launch, "cmd /c start %s", url);
	system(launch);
	sprintf(launch, "x-www-browser '%s' &", url);
        system(launch);
	sprintf(launch, "open '%s'", url);
        system(launch);
}

int	main(int argc, char *argv[])
{
	char *phrase = argv[1];
	char *vars[] = {"RSS_FEED=https://www.kommersant.ru/RSS/news.xml", NULL};
	int fd[2];

	if (pipe(fd) == -1) {
		error("Не могу создать канал");
	}

	pid_t pid = fork();
	if (pid == -1) {
		error("не могу клонировать процесс");
	}
	if (!pid) {
		dup2(fd[1],1);
		close(fd[0]);
		}
		if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u", phrase, NULL, vars) == -1) {
			error("не могу запустить скрипт");
		}

	dup2(fd[0],0);
	close(fd[1]);

	char line[255];
	while (fgets(line, 255, stdin)) {
		if (line[0] == '\t')
			open_url(line + 1);
	}
	return 0;
}
