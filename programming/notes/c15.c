#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int code;
  char *desc;
  int price;
} Product;

Product make_product(int, char *, int);

void save_product(Product *, int);

void delete_products(Product *, unsigned);

// Να γραφεί πρόγραμμα το οποίο θα καταγράφει σε δυναμικά ορισμένο πίνακα δομών
// τα στοιχεία Ν προϊόντων. Στην συνέχεια θα σώζει τον πίνακα σε αρχείο κειμένου
// Στην πρώτη γραμμή του αρχείου θα καταγράφεται το πλήθος των εγγραφών που
// ακολουθούν. Για κάθε προϊόν θα καταγράφονται τα ακόλουθα στοιχεία: Κωδικός,
// Περιγραφή, Τιμή.
int main(void) {
  int N = 2;
  Product *arr = malloc(sizeof(Product) * N);
  arr[0] = make_product(0, "aaa", 420);
  arr[1] = make_product(1, "bbb", 21);
  save_product(arr, 2);
  delete_products(arr, N);
  return 0;
}

Product make_product(int code, char *desc, int price) {
  Product p;
  p.code = code;
  p.desc = (char *)calloc(strlen(desc) + 1, 1);
  strcpy(p.desc, desc);
  p.price = price;
  return p;
}

void delete_products(Product *p, unsigned N) {
  for (unsigned i = 0; i < N; i++) {
    free(p[i].desc);
  }
  free(p);
}

void save_product(Product *products, int size) {
  FILE *f = fopen("c15_demo.txt", "w");
  fprintf(f, "%d\n", size);
  for (unsigned int i = 0; i < size; i++) {
    fprintf(f, "%d\n%s\n%d\n", products[i].code, products[i].desc,
            products[i].price);
  }
  fclose(f);
}
