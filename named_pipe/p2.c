#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// reader process
int main() {
    char buf[32];
    int fd = open("Users/prateeksingh/Documents/code_demo/EOS_Code/named_pipe/file.txt", O_RDONLY);
    if(fd < 0) {
        perror("open() failed");
        _exit(1);
    }

    printf("P2: reading from pipe...\n");
    read(fd, buf, sizeof(buf));
    printf("P2: read from pipe: %s\n", buf);
    close(fd);
    return 0;
}


// terminal2> gcc demo43_p2.c -o p2.out
// terminal2> ./p2.out


