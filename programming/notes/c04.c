#include <stdio.h>
#include <stdlib.h>
// Να γραφεί συνάρτηση η οποία θα δεσμεύει έναν δυναμικό πίνακα double αριθμών Ν
// θέσεων και θα τον αρχικοποιεί με την τιμή L.
double *make_double_initarray(unsigned int, double);

int main(int argc, char *argv[]) {
  double *doubles = make_double_initarray(5, 1.0);

  putchar('[');
  for (unsigned int i = 0; i < 5; i++) {
    printf(" %lf ", doubles[i]);
  }
  putchar(']');
  putchar('\n');
  free(doubles);
  return 0;
}

double *make_double_initarray(unsigned int size, double L) {
  double *arr = (double *)malloc(size * sizeof(double));
  for (unsigned int i = 0; i < size; i++)
    arr[i] = L;

  return arr;
}
