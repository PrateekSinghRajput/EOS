#include <stdio.h>
#include <unistd.h>

int main() {
    int i, ret;
    printf("program started!\n");
    ret = fork();
    if(ret == 0) {
        printf("child: fork() returned: %d\n", ret);
        for(i=0; i<10; i++) {
            printf("child: %d\n", i);
            sleep(1);
        }
        printf("child: program completed!\n");
    }
    else {
        printf("parent: fork() returned: %d\n", ret);
        for(i=0; i<10; i++) {
            printf("parent: %d\n", i);
            sleep(2);
        }
        printf("parent: program completed!\n");
    }
    return 0;
}
