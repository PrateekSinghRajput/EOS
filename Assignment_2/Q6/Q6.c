/*
>>6 Create child process using fork(), then call execl() from that
    child process and run aother command from that. Check the PID, PPID
    Share your observation.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int ret;
    int val=10;
    
    printf("Hi Master\n");
    ret = fork();
    
    if (ret == 0)
    {
        // Child process
        printf("I'm in Child process pid: %d, ppid:%d\n", getpid(), getppid());
        printf("Value Par:%d\n", val);
        printf("Value Par:%d\n", --val);
        
        // Using execl to run a new program (ls command in this case)
        printf("Child is about to execute ls command\n");
        execl("/usr/bin/ls", "ls", "-l", NULL);
        
        // If execl fails, this line will execute
        perror("execl failed");
        exit(1);
    }
    else if (ret > 0)
    {
        // Parent process
        printf("I'm in Parent process pid: %d, ppid: %d\n", getpid(), getppid());
        printf("Value Childdd:%d\n", ++val);
        while(1); // Keep parent running to observe
    }
    else
    {
        perror("Failed to create child");
    }
    
    return 0;
}


/*
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{ 
    int ret;
    int val = 10;
    
    printf("Hi Master (PID: %d)\n", getpid());
    ret = fork();
    
    if (ret == 0)  // Child process
    {
        printf("Child before exec - PID: %d, PPID: %d\n", getpid(), getppid());
        printf("Value in child: %d\n", --val);  // Shows 9
        
        // Replace child process with "ls -l" command
        execl("/bin/ls", "ls", "-l", NULL);
        
        // If execl fails:
        perror("execl failed");
        return 1;
    }
    else if (ret > 0)  // Parent process
    {
        printf("Parent - PID: %d, Child PID: %d\n", getpid(), ret);
        printf("Value in parent: %d\n", ++val);  // Shows 11
        
        // Wait for child to finish
        wait(NULL);
        printf("Parent: Child process finished\n");
    }
    else
    {
        perror("fork failed");
        return 1;
    }
    
    return 0;
}

*/
