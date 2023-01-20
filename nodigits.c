#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

int main(int argc, char **argv) {
	int filedescriptor;
	char buffer[2048] = {};
    char newbuffer[2048] = {};
    int bytes;
    int newbytes = 0;
    int i;

    if (argc <= 1) {
        while((bytes = read(0, buffer, 2048)) != 0) {
            for (i = 0; i < bytes; ++i) {
                if (!isdigit(buffer[i])) {
                    newbuffer[newbytes] = buffer[i];
                    ++newbytes;
                }
            }
            write(1, newbuffer, newbytes);
        }
    } else {
        for (i = 0; i < argc - 1; ++i) {
            filedescriptor = open(argv[i + 1], O_RDWR);
            while ((bytes = read(filedescriptor, buffer, 2048)) > 0) {
                if ((!isdigit(buffer[i]))) {
                    newbuffer[newbytes] = buffer[i];
                    ++newbytes;
                }
                write(1, newbuffer, newbytes);
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
