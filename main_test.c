#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int fd;
    char *line;

    if (argc < 2) {
        printf("Usage: ./a.out <filename>\n");
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("Line: %s", line);
        free(line);
    }

    close(fd);
    return 0;
}
