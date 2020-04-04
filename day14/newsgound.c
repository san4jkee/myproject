#include <stdio.h>
#include <string.h>
#include <errno.h>

int	main(int argc, char *argv[])
{
	char *feeds[] = {"https://www.kommersant.ru/RSS/news.xml",
		"http://www.ura.ru/export/all.rss",
		"http://lenta.ru/l/r/EX/import.rss"};
	int times = 3;
	char *phrase = argv[1];
	int i;
	for (i = 0; i < times; i++) {
		char var[255];
		sprintf(var, "RSS_FEED=%s", feeds[i]);
		char *vars[] = {var, NULL};
		if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1) {
			fprintf(stderr, "Не могу запустить скрипт: %s\n", strerror(errno));
			return 1;
		}
	}
	return 0;
}
