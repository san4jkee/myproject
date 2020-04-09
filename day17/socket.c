#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void error(char *msg)
{       
        fprintf(stderr, "%s: %s\n", msg, strerror(errno));
        exit(1);
} 

int	main(int argc, char *argv[])
{
	char *advice[] = {
		"Кушайте меньшими порциями \r\n",
		"Прикупите облегающие джинсы. Нет, они Вас не полнят. \r\n",
		"Два слова: не годится \r\n",
		"Будьте честгыми хотя бы сегодня. Скажите своему начальнику, что Вы *на самом деле* о нем думаете \r\n",
		"Возможно, Вам стоит подобрать другую прическу\r\n"
	};
	int listener_d = socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in name;
	name.sin_family = PF_INET;
	name.sin_port = (in_port_t)htons(30000);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(listener_d, (struct sockaddr *) &name, sizeof(name)) == -1)
		error("Не могу привязаться к порту");

	listen(listener_d, 10);
	puts("Ожидание подключения");

	while (1) {
		struct sockaddr_storage client_addr;
		unsigned int address_size = sizeof(client_addr);
		int connect_d = accept(listener_d, (struct sockaddr *) &client_addr, &address_size);
		char *msg = advice[rand() % 5];
		send(connect_d, msg strlen(msg), 0);
		close(connect_d);
	}
	return 0;
}
