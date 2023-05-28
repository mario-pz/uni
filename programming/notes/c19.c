#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Να γραφεί συνάρτηση η οποία θα γεμίζει έναν πίνακα χαρακτήρων με τυχαίες
// τιμές.
char *rand_arr(int);

int main(int argc, char *argv[]) {
  srand(time(NULL));
  char *a = rand_arr(10);
  for (unsigned int i = 0; i < 10; i++) {
    printf("%c ", a[i]);
  }
  free(a);
  return 0;
}

char *rand_arr(int N) {
  char *arr = (char *)calloc(N, 1);
  for (unsigned int i = 0; i < 10; i++) {
    arr[i] = 'A' + rand() % 57;
  }
  arr[N] = '\0';
  return arr;
}
