// The original process takes care of creating a child.
// The parent will spawn 8 threads each incrementing a shared variable X by 1
// (for 1 million iterations) while the child will spawn 4 threads each
// decrementing a shared variable Y by 1 (for 1 million iterations). The parent,
// once all its threads have terminated, will print the message: "I am the
// parent, my 8 threads have terminated". The child, once all its threads have
// terminated, will print the message: "I am the child, my 4 threads have
// terminated". Next, the parent will send the value of X to the child and the
// child the value of Y to the parent using pipes. Once the child finishes, the
// parent will print the sum of X + Y to the screen. Note: Be sure to properly
// protect shared resources to avoid race conditions or general synchronization

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PARENT_THREADS 8
#define NUM_CHILD_THREADS 4
#define NUM_ITERATIONS 1000000

int X = 0; // Shared variable incremented by parent threads
int Y = 0; // Shared variable decremented by child threads

pthread_mutex_t x_mutex; // Mutex for protecting X
pthread_mutex_t y_mutex; // Mutex for protecting Y

void *parentThread(void *arg) {
  for (int i = 0; i < NUM_ITERATIONS; i++) {
    pthread_mutex_lock(&x_mutex); // Lock X before incrementing
    X++;
    pthread_mutex_unlock(&x_mutex); // Unlock X
  }
  pthread_exit(NULL);
}

void *childThread(void *arg) {
  for (int i = 0; i < NUM_ITERATIONS; i++) {
    pthread_mutex_lock(&y_mutex); // Lock Y before decrementing
    Y--;
    pthread_mutex_unlock(&y_mutex); // Unlock Y
  }
  pthread_exit(NULL);
}

int main() {
  // Initialize mutexes
  pthread_mutex_init(&x_mutex, NULL);
  pthread_mutex_init(&y_mutex, NULL);

  // Create pipe
  int pipefd[2];
  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  // Create child process
  pid_t pid = fork();

  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid == 0) {
    // Child process
    pthread_t childThreads[NUM_CHILD_THREADS];

    // Create child threads
    for (int i = 0; i < NUM_CHILD_THREADS; i++) {
      pthread_create(&childThreads[i], NULL, childThread, NULL);
    }

    // Wait for child threads to terminate
    for (int i = 0; i < NUM_CHILD_THREADS; i++) {
      pthread_join(childThreads[i], NULL);
    }

    // Print termination message
    printf("I am the child, my 4 threads have terminated.\n");

    // Write Y to the parent through pipe
    close(pipefd[0]); // Close unused read end
    write(pipefd[1], &Y, sizeof(Y));
    close(pipefd[1]);

    exit(EXIT_SUCCESS);
  } else {
    // Parent process
    pthread_t parentThreads[NUM_PARENT_THREADS];

    // Create parent threads
    for (int i = 0; i < NUM_PARENT_THREADS; i++) {
      pthread_create(&parentThreads[i], NULL, parentThread, NULL);
    }

    // Wait for parent threads to terminate
    for (int i = 0; i < NUM_PARENT_THREADS; i++) {
      pthread_join(parentThreads[i], NULL);
    }

    // Print termination message
    printf("I am the parent, my 8 threads have terminated.\n");

    // Read Y from the child through pipe
    close(pipefd[1]); // Close unused write end
    read(pipefd[0], &Y, sizeof(Y));
    close(pipefd[0]);

    // Print sum of X + Y
    int sum = X + Y;
    printf("Sum of X + Y: %d\n", sum);
  }

  // Destroy mutexes
  pthread_mutex_destroy(&x_mutex);
  pthread_mutex_destroy(&y_mutex);

  return 0;
}
