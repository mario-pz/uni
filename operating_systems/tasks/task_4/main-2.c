#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int **A, **D;
int N, p, m;

void* find_max(void* arg) {
    int start = *((int*) arg);
    int end = start + N/p;
    int max_val = A[start][0];
    for (int i = start; i < end; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] > max_val) {
                max_val = A[i][j];
            }
        }
    }
    *((int*) arg) = max_val;
    pthread_exit(NULL);
}

void* calc_distance(void* arg) {
    int start = *((int*) arg);
    int end = start + N/p;
    for (int i = start; i < end; i++) {
        for (int j = 0; j < N; j++) {
            D[i][j] = m - A[i][j];
        }
    }
    pthread_exit(NULL);
}

int main() {
    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter p: ");
    scanf("%d", &p);
    A = (int**) malloc(N * sizeof(int*));
    D = (int**) malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        A[i] = (int*) malloc(N * sizeof(int));
        D[i] = (int*) malloc(N * sizeof(int));
    }
    printf("Enter elements of A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    pthread_t threads[p];
    int thread_args[p];
    for (int i = 0; i < p; i++) {
        thread_args[i] = i * N/p;
        pthread_create(&threads[i], NULL, find_max, &thread_args[i]);
    }
    for (int i = 0; i < p; i++) {
        pthread_join(threads[i], NULL);
    }
    m = thread_args[0];
    for (int i = 1; i < p; i++) {
        if (thread_args[i] > m) {
            m = thread_args[i];
        }
    }

    for (int i = 0; i < p; i++) {
        thread_args[i] = i * N/p;
        pthread_create(&threads[i], NULL, calc_distance, &thread_args[i]);
    }
    for (int i = 0; i < p; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("D:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(D[i]);
    }
    free(A);
    free(D);
    return 0;
}

