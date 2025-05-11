#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include <sys/sem.h>
#include<sys/shm.h>


#define KEY 2022

                   //in a shared-segment, in user-spac
struct shmarea {   //this is a shared-data object, 
  unsigned long count;     //a shared-data variable
  char message[30];

}; 

struct shmarea *shma;


int main(){


   int id;
  
   unsigned long int i=0, j=0;
   
    id =  shmget(KEY,2*2*getpagesize(),IPC_CREAT|0600);
       
     if(id <0) 
     { 
     perror("error in shmget"); 
     exit(5); 
     }
     
    shma = shmat(id,0,0); 

    shma->count++;    

  printf("Shared Memory Data Will Display in process1\n");
  printf("Count %d\n",shma->count);
  printf("Message %s\n",shma->message);
  scanf("%s",shma->message);
  printf("New Message will update \n");


return 0;

}

