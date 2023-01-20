#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	int filedescriptor;
	char buffer[2048] = {};
	int bytes;

	filedescriptor = open(argv[1], O_RDWR);

	bytes = read(filedescriptor, buffer, 2048);

	write(1, buffer, bytes);
	close(filedescriptor);
	return 0;
}
