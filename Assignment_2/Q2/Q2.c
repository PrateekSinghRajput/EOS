/*
>>2 repeat the  problem 1, by changing the nice values of each instance,
    using renice command, use renice to modify the values in +ve range only,
    like +5 | +10 | +15 ­ observe using ps and top commands – what are your
    conclusions ?

    Note : with administrative privileges, you can change the nice priority
           values to ­-ve values, which will provide very large time­share values
           to processes !!! you can assign ­5 | ­10 | ­10 | ­20 to different
           processes on a given processor/scheduler instance
           refer to manual pages of renice !!!
*/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{ 
 int ret=0;//stack, add space gets copied
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
