#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int cnt, ret, pfd[2], s;
    char str1[32], str2[32]; 
    ret = pipe(pfd);
    if(ret < 0) {
        perror("pipe() failed");
        _exit(1);
    }
    //pfd[1] -- writer fd and pfd[0] -- reader fd
    
    ret = fork();
    if(ret == 0) {
        // child process -- writer process
        close(pfd[0]); // close read end
        printf("child: enter a string: ");
        scanf("%s", str1);
        printf("child: writing into pipe: %s\n", str1);
        write(pfd[1], str1, strlen(str1)+1);
        close(pfd[1]);
    }
    else {
        // parent process -- reader process
        close(pfd[1]); // close write end
        printf("parent: reading from pipe.\n");
        cnt = read(pfd[0], str2, sizeof(str2));
        printf("parent: read %d bytes from pipe: %s\n", cnt, str2);
        close(pfd[0]);

        waitpid(-1, &s, 0);
    }
    return 0;
}
