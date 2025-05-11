#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include <sys/sem.h>
#include<sys/shm.h>
#include <string.h>



#define KEY 2022

//in a shared-segment, in user-space
struct shmarea {   //this is a shared-data object, 
                   
  unsigned long count;     //a shared-data variable
  char message[30];

}; 

struct shmarea *shma;


int main(){


   int id;
  
   unsigned long int i=0, j=0;
   
   id =  shmget(KEY,2*2*getpagesize(),IPC_CREAT|0600); //shared Memory 
   //is key is not match then is created new key (IPC_CREAT)
   
    if(id <0) { 
    perror("error in shmget"); 
    exit(5); 
    }
     
    shma = shmat(id,0,0); 

   shma->count = 100; //this is the initial value  

  printf("Shared Memory Data Will Display in Process2\n");
  printf(" Count %d\n",shma->count);
  printf("Message %s\n",shma->message);
  printf("Enter a message to store in Shared Memory \n");
  scanf("%s",shma->message);

return 0;

}

