#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Να γραφεί συνάρτηση η οποία θα δέχεται ως όρισμα ένα ταξινομημένο πίνακα
// πραγματικών αριθμών και θα τοποθετεί σε αυτόν ένα πραγματικό αριθμό, ο
// οποίος, επίσης, δίδεται ως όρισμα και θα τον τοποθετεί στην κατάλληλη θέση
// ώστε ο πίνακας να παραμένει ταξινομημένος. Για την υλοποίηση της άσκησης δεν
// θα εκτελεστεί ταξινόμηση.
void insert_number(double **, size_t *, double);
void print_array(double const *const, size_t);

int main(void) {
  size_t size = 5;
  double *numbers = (double *)malloc(size * sizeof(double));
  *numbers = 1.5;
  numbers[1] = 4;
  numbers[2] = 7.8;
  numbers[3] = 12.3;
  numbers[4] = 16.2;

  print_array(numbers, size);
  insert_number(&numbers, &size, 0.5);
  insert_number(&numbers, &size, 8.8);
  insert_number(&numbers, &size, 12.3);
  insert_number(&numbers, &size, 20);

  print_array(numbers, size);
  free(numbers);
  return 0;
}

void insert_number(double **numbers, size_t *size, double number) {
  double *new_numbers = (double *)malloc((*size + 1) * sizeof(double));
  double *item_old = *numbers, *item_new = new_numbers;

  bool f = true;
  while (item_old < *numbers + *size) {
    if (*item_old > number && f) {
      f = false;
      *item_new++ = number;
    }
    *item_new++ = *item_old++;
  }
  if (f) { // ο αριθμός είναι μεγαλύτερος από το τελευταίο στοιχείο
    new_numbers[*size] = number;
  }
  free(*numbers);
  *numbers = new_numbers;
  *size += 1;
}

void print_array(double const *const numbers, size_t size) {
  printf("[ ");
  for (size_t i = 0; i < size; i++) {
    printf("%lf ", numbers[i]);
  }
  printf("]\n");
}
