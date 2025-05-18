#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// who | wc
int main() {
    int cnt, ret, err, pid1, pid2, s, pfd[2];
    ret = pipe(pfd);
    if(ret < 0) {
        perror("pipe() failed");
        _exit(1);
    }
    //pfd[1] -- writer fd and pfd[0] -- reader fd
    
    pid1 = fork();
    if(pid1 == 0) {
        // writer process 
        close(pfd[0]);
        dup2(pfd[1], STDOUT_FILENO);
        close(pfd[1]);

        err = execlp("who", "who", NULL);
        if(err < 0) {
            perror("exec() failed");
            _exit(1);
        }
    }    
    
    pid2 = fork();
    if(pid2 == 0) {
        // reader process
        close(pfd[1]);
        dup2(pfd[0], STDIN_FILENO);
        close(pfd[0]);

        err = execlp("wc", "wc", NULL);
        if(err < 0) {
            perror("exec() failed");
            _exit(1);
        }
    }    

    close(pfd[1]);
    close(pfd[0]);

    waitpid(pid1, &s, 0);
    waitpid(pid2, &s, 0);
    return 0;
}