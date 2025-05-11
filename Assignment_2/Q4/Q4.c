/*>>4 Create child process using fork(), try to observe
    the different states of processes.
    Observe the O/P of ps and top
*/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{ 
 int ret;//stack, add space
 int val=10;
 
 printf("Hi Master\n");
 ret = fork();
 
  if (ret == 0 )
  {
     printf("I'm in Child process pid: %d, ppid:%d\n", getpid(),getppid());
     printf("Value Par:%d\n",val);
     printf("Value Par:%d\n",--val);
     while(1);
  }
  
 else  if (ret > 0)
   {
     printf("I'm in Parent procss pid: %d, ppid: %d\n",getpid(),getppid());
     //printf("Parent process pid: %d, child process ID: %d\n",getpid(),ret);
     printf("Value Chi:%d\n",++val);
     while(1);
   }
 
 else
 	perror("Failed to create child");
return 0;
}
