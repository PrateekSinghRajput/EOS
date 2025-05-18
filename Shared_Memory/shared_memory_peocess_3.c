#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include <sys/sem.h>
#include<sys/shm.h>



#define KEY 2121


struct shmarea {   //this is a shared-data object, 
                   //in a shared-segment, in user-space

  unsigned long count;     //a shared-data variable
  unsigned long count1;    //another, shared-data variable
  unsigned long count2;    //""""
  
}; 

struct shmarea *shma;



int main(){


   int ret,ret1,ret2,status,id;
  
   unsigned long int i=0, j=0;
   
       id =  shmget(KEY,2*2*getpagesize(),IPC_CREAT|0600);
       
     if(id <0) 
     { 
     perror("error in shmget"); 
     exit(5); 
     }
     
        shma = shmat(id,0,0); 


    shma->count++;    
    shma->count1++;
    shma->count2++;

  printf("Now Counter Value will be Display \n");
  printf("Count %d\n",shma->count);
  printf("Count1 %d\n",shma->count1);
  printf("Count2 %d\n ",shma->count2);


return 0;

}

