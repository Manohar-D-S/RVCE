#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int ip_fd, op_fd;

    if (argc != 3) {  // Check for correct number of arguments
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        return EXIT_FAILURE;
    }

    ip_fd = link(argv[1], argv[2]);
    if(ip_fd == -1) {
        perror("link error");
        return 2;
    }
    
    op_fd = unlink(argv[1]);
    if(op_fd == -1) {
        perror("unlink error");
        return 3;
    }
    
    close(ip_fd);
    close(op_fd);
    return 0;
}

