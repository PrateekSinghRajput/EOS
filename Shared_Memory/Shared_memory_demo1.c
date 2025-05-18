#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include <sys/sem.h>
#include<sys/shm.h>
#include <string.h>



#define KEY 2121


struct shmarea {   //this is a shared-data object, 
                   //in a shared-segment, in user-space

  unsigned long count;     //a shared-data variable
  unsigned long count1;    //another, shared-data variable
  unsigned long count2;    //""""
 // char message[30];

}; 

struct shmarea *shma;



int main(){


   int ret,ret1,ret2,status,id;
  
   unsigned long int i=0, j=0;
   
   id =  shmget(KEY,2*2*getpagesize(),IPC_CREAT|0600); //shared Memory 
   //is key is not match then is created new key (IPC_CREAT)
   
    if(id <0) { perror("error in shmget"); exit(5); }
     
        shma = shmat(id,0,0); 


  printf("Hi I Am Run Function one \n"); 
  shma->count = 5533; //this is the initial value  
  shma->count1 = 6533; //this is the initial value  
  shma->count2 = 7533; //this is the initial value  
  //shma->message = "\r\n Process_1 Will Run";  
 

  printf("Now Counter Value will be Display \n");
  printf(" Count %d\n",shma->count);
  printf(" Count1 %d\n",shma->count1);
  printf(" Count2 %d\n",shma->count2);
  //printf("Process1 Message Will Printf %s \n",shma->message);


return 0;

}

