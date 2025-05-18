#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// writer process
int main() {
    char buf[32];
    int fd = open("Users/prateeksingh/Documents/code_demo/EOS_Code/named_pipe/file.txt", O_WRONLY);
    if(fd < 0) {
        perror("open() failed");
        _exit(1);
    }
    printf("P1: enter a string: ");
    scanf("%s", buf);
    write(fd, buf, strlen(buf)+1);
    printf("P1: written to pipe: %s\n", buf);
    close(fd);
    return 0;
}

// terminal1> mkfifo desd_fifo
// terminal1> gcc demo43_p1.c -o p1.out
// terminal1> ./p1.out

