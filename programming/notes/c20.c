#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Να γραφεί συνάρτηση η οποία θα γεμίζει έναν πίνακα χαρακτήρων με τυχαίες
// μοναδικές τιμές.
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
  int i, j, random_num;
  char random_char;
  for (i = 0; i < N; i++) {
    random_num = rand() % 52;
    random_char =
        (random_num < 26) ? (random_num + 'A') : (random_num + 'a' - 26);
    for (j = 0; j < i; j++) {
      if (arr[j] == random_char) {
        i--;
        break;
      }
    }
    if (j == i) {
      arr[i] = random_char;
    }
  }
  return arr;
}
