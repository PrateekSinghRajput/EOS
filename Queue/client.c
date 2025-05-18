#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

#define KEY1 1552

struct message {
    long mtype;
    char mtext[100];
};

    int msgqid, ret1;
    struct message msg;
    int message_type;
    int choice;
    
    
    void Received_data();
    void Send_data();

int main() {

    // Get the message queue
    msgqid = msgget(KEY1, 0666 | IPC_CREAT); 
    
    if (msgqid < 0){
        perror("msgget");
        exit(1);
    }


 while(1){
    
    printf("Enter Your Choice \n1.--> Send DATA \n2.--> Received DATA  \n3.--> EXIT \n");
    scanf("%d",&choice);
    
    switch(choice){
    
    	case 1:
    	       Send_data();
    	       break;
    	       
    	case 2:
    	       Received_data();
    	       break;
    	       
        case 3:
              exit(1);
              
              
      }
      
    }
  
    return 0;
}



void Received_data(){

		   // Receive the message
    printf("Enter your message type \n");
    scanf("%d",&message_type);
    msg.mtype = message_type;
    ret1 = msgrcv(msgqid, &msg, sizeof(struct message),message_type, 0);
    
     if (ret1 < 0) {
         perror("msgrcv");
         exit(1);
      }

    printf("Received message: %s\n", msg.mtext);
    
    }


void Send_data(){


      printf("Enter your Message Type \n");
      scanf("%d",&message_type);
      msg.mtype = message_type;
      
      printf("Enter your Message what you to send \n");
      scanf("%s",msg.mtext);
      
     // strcpy(msg.mtext, "Hello, message queue!");
    
    

     // Send the message
     ret1 = msgsnd(msgqid, &msg, sizeof(struct message), 0); 
    
     if (ret1 < 0)
    {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent successfully.\n");
    
    }


