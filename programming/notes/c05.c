#include <stdio.h>
#include <stdlib.h>

// Να γραφεί συνάρτηση η οποία θα τοποθετεί σε έναν πίνακα ακεραίων Ν θέσεων
// τους Ν πρώτους αριθμούς της ακολουθίας Fibonacci.
int *fibo_arr(int);

int main(void) {
  int *a = fibo_arr(5);
  for (unsigned int i = 0; i < 5; i++) {
    printf("%d ", a[i]);
  }
  putchar('\n');
  free(a);
  return 0;
}

int *fibo_arr(int N) {
  if (N == 0 || N == 1) {
    return 0;
  }

  int *arr = (int *)malloc(N * sizeof(int));
  if (arr == NULL) {
    printf("Δεν υπάρχει διαθέσιμη μνήμη.\n");
    return NULL;
  }
  arr[0] = 0;
  arr[1] = 1;
  for (unsigned int i = 2; i < N; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  return arr;
}
