#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	int filedescriptor;
	char buffer[2048] = {};
	int bytes;
    int i;

    if (argc <= 1) {
        bytes = read(0, buffer, 2048);
        write(1, buffer, bytes);
    } else {
        for (i = 0; i < argc; ++i) {
            filedescriptor = open(argv[i + 1], O_RDWR);
            bytes = read(filedescriptor, buffer, 2048);
            if (bytes <= 0) {
                if (bytes == -1) {
                    perror("open");
                    exit(1);
                }
                break;
            }
            write(1, buffer, bytes);
	        close(filedescriptor);
        }
    }
    return 0;
}
