#include <stdio.h>
// Να γραφεί συνάρτηση η οποία θα ελέγχει αν σε ένα πίνακα χαρακτήρων βρίσκεται
// μία συγκεκριμένη τιμή.
int find_c(char *, int, char);
int main(void) {
  if (find_c("Test", 4 + 1, 's')) {
    printf("Found.\n");
  } else {
    printf("Not found.\n");
  }
}

int find_c(char *string, int N, char c) {
  for (unsigned int i = 0; i < N; i++) {
    if (c == string[i]) {
      return 0;
    }
  }
  return -1;
}
