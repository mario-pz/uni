#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Για ευκολία εκχώρησης δεδομένων

// Να γραφεί συνάρτηση που θα δέχεται τους βαθμούς Μ φοιτητών σε Ν μαθήματα και
// θα επιστρέφει τον μέσο όρο του κάθε μαθήματος.
int get_mo(int *, int);

int main(void) {
  srand(time(0));

  int **amm = (int **)malloc(5 * sizeof(int *));
  for (int i = 0; i < 5; i++) {
    amm[i] = (int *)malloc(5 * sizeof(int));
    for (int j = 0; j < 5; j++) {
      amm[i][j] = rand() % 9 + 1;
    }
  }

  for (int j = 0; j < 5; j++) {
    printf("Ο μέσος όρος του μαθήματος είναι: %d\n", get_mo(amm[j], 5));
  }

  // Clear student grades
  for (int i = 0; i < 5; i++) {
    free(amm[i]);
  }
  free(amm);

  return 0;
}

int get_mo(int *M, int N) {
  int mo = 0;
  for (int i = 0; i < N; i++) {
    mo += M[i];
  }
  return mo / N;
}
