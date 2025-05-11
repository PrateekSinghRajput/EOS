/*
>>3 using chrt. utility, can you modify scheduling policy of active applications/
    processes, in problems 1) to FIFO or RR, with appropriate real­time
    priorities – use the following policy and priority assignments ???

    a) assign FIFO with equal priority to a few processes and assign TS policy
       to a few processes – you need to assign these processes to a specific
       processor / scheduler instance
    b) assign RR with equal priority to a few processes and test – once again,
       you need to assign these processes to a specific processor/scheduler
       instance.
*/
       
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{ 
 int ret=0;   //stack, add space
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
