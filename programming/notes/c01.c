#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Να γραφεί πρόγραμμα το οποίο θα υλοποιεί το παιχνίδι “Μάντεψε τον Αριθμό” με
// όρια τυχαίων αριθμών [1..100] και 7 προσπάθειες.
int main(void) {
  unsigned int tries = 7;
  srand(time(NULL));
  int n = rand() % 99 + 1;
  do {
    int nn = 0;
    printf("Μάντεψε τον αριθμό: ");
    scanf("%d", &nn);
    if (nn == n) {
      printf("Το βρήκες!\n");
      break;
    } else if (nn > n) {
      printf("Θες μικρότερο.\n");
      tries--;
    } else {
      printf("Θες μεγαλύτερο.\n");
      tries--;
    }
  } while (tries > 0);

  if (tries == 0) {
    printf("Έχασες.\n");
  }

  return 0;
}
