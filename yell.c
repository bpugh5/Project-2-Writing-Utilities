#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

int main(int argc, char **argv) {
	int filedescriptor;
	char buffer[2048] = {""};
	int bytes;
    int i;

    if (argc <= 1) {
        while((bytes = read(0, buffer, 2048)) > 0) {
            for (i=0; i < bytes; ++i) {
                buffer[i] = toupper(buffer[i]);
                printf("%c", buffer[i]);
            }
            write(1, buffer, bytes);
        }
    } else {
        for (i = 0; i < argc; ++i) {
            filedescriptor = open(argv[i + 1], O_RDWR);
            while ((bytes = read(filedescriptor, buffer, 2048)) > 0) {
                write(1, buffer, bytes);
            }
            if (bytes < 0) {
                perror("read");
                exit(1);
            }
        }
	    close(filedescriptor);
    }
    return 0;
}
