/*
 * @ice21390179
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void p0();
void p1();
void p2();

int main() {
  pid_t pid0 = fork();
  if (pid0 == 0) {
    p0();
    exit(0);
  } else if (pid0 < 0) {
    perror("σφάλμα fork");
    exit(1);
  }

  wait(NULL);

  return 0;
}

void p0() {
  printf("P0 PID: %d\n", getpid());

  pid_t pid1 = fork();
  if (pid1 == 0) {
    p1();
    exit(0);
  } else if (pid1 > 0) {
    p2();
  } else {
    perror("σφάλμα fork");
    exit(1);
  }
}

void p1() {
  printf("P1 PID: %d\n", getpid());

  int pipefd[2];
  if (pipe(pipefd) == -1) {
    perror("σφάλμα pipe");
    exit(1);
  }

  int status;
  pid_t pid3 = fork();
  if (pid3 == 0) {
    close(pipefd[0]);
    char message[] = "Hello, P1!";
    write(pipefd[1], message, sizeof(message));
    close(pipefd[1]);
    exit(0);
  } else if (pid3 > 0) {
    close(pipefd[1]);
    char message[100];
    read(pipefd[0], message, sizeof(message));
    printf("P1: Λήφθηκε μήνυμα από την P3: %s\n", message);
    close(pipefd[0]);

    pid_t pid4 = fork();
    if (pid4 == 0) {
      printf("P4 PID: %d\n", getpid());
      exit(5);
    } else if (pid4 > 0) {
      waitpid(pid4, &status, 0);
      printf("P1: Η P4 ολοκληρώθηκε με κωδικό εξόδου %d\n",
             WEXITSTATUS(status));
    } else {
      perror("σφάλμα fork");
      exit(1);
    }
  } else {
    perror("σφάλμα fork");
    exit(1);
  }

  exit(0);
}

void p2() {
  printf("P2 PID: %d\n", getpid()); // εκτύπωση του PID της διεργασίας P2

  int N;
  printf("Εισάγετε τον αριθμό των παιδικών διεργασιών για να δημιουργηθούν: ");
  scanf("%d", &N); // ανάγνωση του αριθμού N από το χρήστη

  int i;
  for (i = 0; i < N; i++) {
    pid_t pid = fork(); // δημιουργία νέας διεργασίας (P3, P4, κλπ.)
    if (pid == 0) { // παιδική διεργασία (P3, P4, κλπ.)
      printf("P%d PID: %d, PPID: %d\n", i + 1, getpid(), getppid());
      exit(0);
    } else if (pid < 0) {
      perror("σφάλμα fork");
      exit(1);
    }
  }

  int status;
  pid_t pid_child;
  int completed_children = 0;

  while (completed_children < N) {
    pid_child = waitpid(-1, &status, WNOHANG);
    if (pid_child > 0) {
      printf("P2: Η παιδική διεργασία με PID %d ολοκληρώθηκε\n", pid_child);
      completed_children++;
    }
  }

  printf("P2: Η παιδική διεργασία με PID %d ολοκληρώθηκε\n", pid_child);
  exit(0);
}
