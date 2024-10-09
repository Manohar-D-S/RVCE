#include <stdio.h>      //IO functions
#include <stdlib.h>     //general utilities
#include <errno.h>
#include <unistd.h>     //unlink and link 

int main(int argc, char* argv[]) {
    int op_fd;
    
    // if (argc != 2) {  // Check for correct number of arguments
    //     fprintf(stderr, "Usage: file1\n");
    //     return EXIT_FAILURE;
    // }       /*optional  */

    op_fd = unlink(argv[1]);
    if(op_fd == -1) {
        perror("unlink error");
        return 3;
    }

}

