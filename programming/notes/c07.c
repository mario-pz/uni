#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Να γραφεί συνάρτηση η οποία θα επιστρέφει τους δύο μικρότερους αριθμούς που
// βρίσκονται σε ένα πίνακα Ν θέσεων. Ο πίνακας θα σαρωθεί μόνο μία φορά.
int *find_two_min(int *, int);

int main(void) {
  int m[5] = {10, 60, 50, 20, 36};
  int *ms = find_two_min(m, 5);
  printf("[%d, %d]\n", ms[0], ms[1]);
  free(ms);
  return 0;
}

int *find_two_min(int *arr, int N) {
  if (N <= 2) {
    printf("Λάθος χρήση συνθήκης\n");
    return NULL;
  }
  int first, second;

  // Ο αλγόριθμους για να πετύχει δεν πρέπει το first, second να είναι μηδέν
  first = second = INT_MAX;

  for (unsigned int i = 0; i < N; i++) {
    if (arr[i] < first) {
      second = first;
      first = arr[i];
    } else if (arr[i] < second && arr[i] != first)
      second = arr[i];
  }
  int *mins = (int *)malloc(2 * sizeof(int));
  if (mins == NULL) {
    printf("Αποτυχία δέσμευσης στην μνήμη.\n");
    return NULL;
  }
  mins[0] = first;
  mins[1] = second;
  return mins;
}
