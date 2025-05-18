#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>

#define MAX 5

struct cirque {
    int arr[MAX];
    int front, rear;
    int count;
};

void cq_init(struct cirque *q) {
    memset(q->arr, 0, sizeof(q->arr));
    q->front = -1;
    q->rear = -1;
    q->count = 0;
}

void cq_push(struct cirque *q, int val) {
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = val;    
    q->count++;
}

int cq_pop(struct cirque *q) {
    int val;
    q->front = (q->front + 1) % MAX;
    val = q->arr[q->front];    
    q->count--;
    return val;
}

int cq_empty(struct cirque *q) {
    return q->count == 0 ? 1 : 0;
}

int cq_full(struct cirque *q) {
    return q->count == MAX ? 1 : 0;
}

void sigint_handler(int sig) {
    printf("bye!\n");
}

struct cirque cq;
sem_t sf, se;
pthread_mutex_t sm;

void* producer(void *param) {
    int val;
    sleep(10);
    while(1) {
        // P(se);
        sem_wait(&se);
        // lock(sm);
        pthread_mutex_lock(&sm);
        val = rand() % 100;
        cq_push(&cq, val);
        printf("WR: %d\n", val);
        // unlock(sm);
        pthread_mutex_unlock(&sm);
        // V(sf);
        sem_post(&sf);
        sleep(1);
    }
    return NULL;
}

void* consumer(void *param) {
    int val;
    //sleep(10);
    while(1) {
        // P(sf);
        sem_wait(&sf);
        // lock(sm);
        pthread_mutex_lock(&sm);
        val = cq_pop(&cq);
        printf("RD: %d\n", val);
        // unlock(sm);
        pthread_mutex_unlock(&sm);
        // V(se);
        sem_post(&se);
        sleep(1);
    }
    return NULL;
}

int main() {
    struct sigaction sa;
    pthread_t pt, ct;
    int ret;

    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = sigint_handler;
    ret = sigaction(SIGINT, &sa, NULL);

    // sf = 0, se = MAX, sm = unlocked
    sem_init(&sf, 0, 0);
    sem_init(&se, 0, MAX);
    pthread_mutex_init(&sm, NULL);

    pthread_create(&pt, NULL, producer, NULL);
    pthread_create(&ct, NULL, consumer, NULL);
    
    pause();

    pthread_mutex_destroy(&sm);
    sem_destroy(&se);
    sem_destroy(&sf);
    return 0;
}


