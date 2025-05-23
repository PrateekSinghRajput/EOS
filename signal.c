#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo) {
    if (signo == SIGUSR2) { // SIGUSR1 = -10 ; SIGUSR2 = -12
        printf("received SIGUSR2\n");
        for (int i = 0; i < 20; printf("%d ", i++));
        printf("\n");
    }
}

int main(void) {
    void (*ret)(int);
    ret = signal(SIGUSR2, sig_handler);
    
    if (ret == SIG_ERR) {
        printf("\ncan't catch SIGUSR2\n");
    }
    
    // A long long wait so that we can easily issue a signal to this process
    printf("PID: %d\n", getpid());
    
    while (1) {
        printf("Enjoying the while ???\n");
        sleep(1);
    }
    
    return 0;
}


//kill -10 5314