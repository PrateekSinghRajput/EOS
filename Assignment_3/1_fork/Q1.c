/* Create a program, have 2 child created from the parent
    process and establish pipe ipc between 2 childs.*/
    

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {

    int ret, ret1;
    int pfd[2];

    char wr_buf[512];
    char buffer[512];

    ret = pipe(pfd);
    
    if (ret == -1) {
        perror("error in pipe\n");
        exit(1);
    }

    ret = fork(); //first fork

    if (ret == -1) {
        perror("Failed to create child...\n");
        exit(1);
        
    } else if (ret == 0) { // First child will created
        printf("I am First child of parent...\n");
        close(pfd[1]); 
     
        while (1) {
        
            ret = read(pfd[0], buffer, sizeof(buffer));
            
            if (ret > 0) {
              
                printf("First child received: %s\n", buffer);
                
            }
             
        }
        
        close(pfd[0]);
        exit(0); 
        
    } else if (ret > 0) { // Parent process
    
        printf("I am Parent process...\n");
        
        ret1 = fork(); // second fork

        if (ret1 == -1) {
            perror("Failed to create child...\n");
            exit(1);
            
        } else if (ret1 == 0) { // Second child will created
            printf("I am second child of your parent...\n");
            
            close(pfd[0]); 
            printf("Enter a message form child 2: ");
            scanf("%s", wr_buf);
            write(pfd[1], wr_buf, strlen(wr_buf));
            close(pfd[1]); 
            // printf("Enter Sucessfully Send ");
            exit(0); 
        }
    }

 wait(NULL);
 wait(NULL);
    return 0;
}

