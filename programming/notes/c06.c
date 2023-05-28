#include <stdio.h>
#include <stdlib.h>

// Να γραφεί συνάρτηση η οποία θα επιστρέφει τον μεγαλύτερο και τον μικρότερο
// αριθμό που βρίσκεται σε ένα ακέραιο πίνακα Ν θέσεων.
int *find_minmax(int *, unsigned);
int max(int *, unsigned);
int min(int *, unsigned);

int main(void) {
  int arr[5] = { 1, 2, 3, 4, 5 };

  {
  	printf("[ ");
  	int const* item = arr;
  	while (item < arr + 5) {
  		printf("%d ", *item++);
  	}
  	printf("]\n");
  }
  
  int *t = find_minmax(arr, 5);
  printf("[ %d, %d ]\n", t[0], t[1]);
  free(t);
  return 0;
}

int *find_minmax(int *arr, unsigned N) {
  if (N <= 2) {
    printf("Λάθος χρήση συνάρτησης.\n");
    return NULL;
  }
  int *tuple = calloc(2, sizeof(int));
  tuple[0] = max(arr, N);
  tuple[1] = min(arr, N);
  return tuple;
}

int max(int *arr, unsigned N) {
  int max = *arr; // το μηδέν δεν είναι απαραίτητα ο μεγαλύτερος αριθμός του πίνακα
  for (unsigned i = 1; i < N; i++) {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

int min(int *arr, unsigned N) {
  int min = *arr; // το μηδέν δεν είναι απαραίτητα ο μικρότερος αριθμός του πίνακα
  for (unsigned i = 1; i < N; i++) {
    if (arr[i] < min)
      min = arr[i];
  }
  return min;
}
