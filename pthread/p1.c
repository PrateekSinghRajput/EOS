#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* func1(void *param) {
    int i;
    for(i=1; i<=10; i++) {
        printf("func1: %d\n", i);
        sleep(1);
    }
    return NULL;
}

void* func2(void *param) {
    int i;
    for(i=1; i<=10; i++) {
        printf("func2: %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    int i, ret;
    pthread_t t1, t2;
    ret = pthread_create(&t1, NULL, func1, NULL);
    ret = pthread_create(&t2, NULL, func2, NULL);
    for(i=1; i<=10; i++) {
        printf("main : %d\n", i);
        sleep(1);
    }
    return 0;
}


