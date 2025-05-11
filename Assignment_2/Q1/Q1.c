/*1 Using while1.c provided, do following activities.

   > compile and load 2 instance in background and check the ps and top command
   > do the above step again and observe.
   > Use taskset to run the process on a given cpu no.
*/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{ 
 int ret=0;//stack, add space
 int val=10;
 
 printf("Hi Master\n");
 
  if (ret == 0 )
  {
     printf("I'm in Child process pid: %d, ppid:%d\n", getpid(),getppid());
     while(1);
  }
  
 else  if (ret > 0)
   {
     printf("I'm in Parent procss pid: %d, ppid: %d\n",getpid(),getppid());
     while(1);
   }
 
 else
 	perror("Failed to create child");
return 0;
}
