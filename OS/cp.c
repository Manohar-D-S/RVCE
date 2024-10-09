#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 8192

int main(int argc, char* argv[]) {
    int ip_fd, op_fd;
    ssize_t ret_in, ret_out;
    char buffer[BUF_SIZE];

    if (argc != 3) {  // Check for correct number of arguments
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        return EXIT_FAILURE;
    }

    ip_fd = open(argv[1], O_RDONLY);  // Open source file
    if (ip_fd == -1) {
        perror("Error while opening file1");
        return EXIT_FAILURE;
    }

    op_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);  // Open target file
    if (op_fd == -1) {
        perror("Error while opening file2");
        close(ip_fd);
        return EXIT_FAILURE;
    }

    while ((ret_in = read(ip_fd, buffer, BUF_SIZE)) > 0) {
        ret_out = write(op_fd, buffer, ret_in);
        if (ret_out != ret_in) {
            perror("Error writing to file");
            close(ip_fd);
            close(op_fd);
            return EXIT_FAILURE;
        }
    }

    if (ret_in == -1) {
        perror("Error reading from file");
    }

    close(ip_fd);
    close(op_fd);
    return EXIT_SUCCESS;
}

