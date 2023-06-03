#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 3
#define NUM_ITERATIONS 10

sem_t sem_one, sem_two, sem_three;

void *print_one(void *arg) {
    int i;
    for (i = 0; i < NUM_ITERATIONS; i++) {
        sem_wait(&sem_one);
        printf("<ONE>");
        sem_post(&sem_two);
    }
    pthread_exit(NULL);
}

void *print_two(void *arg) {
    int i;
    for (i = 0; i < NUM_ITERATIONS; i++) {
        sem_wait(&sem_two);
        printf("<TWO>");
        sem_post(&sem_three);
    }
    pthread_exit(NULL);
}

void *print_three(void *arg) {
    int i;
    for (i = 0; i < NUM_ITERATIONS; i++) {
        sem_wait(&sem_three);
        printf("<THREE>");
        sem_post(&sem_one);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];

    sem_init(&sem_one, 0, 1);
    sem_init(&sem_two, 0, 0);
    sem_init(&sem_three, 0, 0);

    pthread_create(&threads[0], NULL, print_one, NULL);
    pthread_create(&threads[1], NULL, print_two, NULL);
    pthread_create(&threads[2], NULL, print_three, NULL);

    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem_one);
    sem_destroy(&sem_two);
    sem_destroy(&sem_three);

    return 0;
}

