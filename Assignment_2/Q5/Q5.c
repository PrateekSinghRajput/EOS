/*
>>5 Create a process and implement execl() to run another command.
    Observe the O/P in top and ps. Check the PID and PPID and share
    your observation.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        printf("Child process - PID: %d, PPID: %d\n", getpid(), getppid());
        
        // Replace the child process with 'ls -l' using execl
        execl("/usr/bin/ls", "ls", "-l", NULL);
        printf("ls command used from execl function.");
        
        // If execl fails
        perror("execl failed");
        return 1;
        while(1);
    } else if (pid > 0) {
        // Parent process
        printf("Parent process - PID: %d, Child PID: %d\n", getpid(), pid);
        
        // Wait for the child to complete
        wait(NULL);
        printf("Child process completed.\n");
        while(1);
    } else {
        // Fork failed
        perror("fork failed");
        return 1;
    }
    
    return 0;
}
