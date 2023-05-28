#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int code;
  char *desc;
  int price;
} Product;

// Να γραφεί πρόγραμμα το οποίο θα διαβάζει το αρχείο της προηγούμενης άσκησης,
// θα καταγράφει τα στοιχεία σε δυναμικά ορισμένο πίνακα και θα τυπώνει τα
// στοιχεία στην οθόνη.
int main() {
  Product *items;

  FILE *file = fopen("c15_demo.txt", "r");
  if (file == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  int size = 0;
  fscanf(file, "%d\n", &size);

  items = malloc(size * sizeof(Product));
  char *buffer = NULL;
  size_t bufferSize = 0;
  for (unsigned i = 0; i < size; i++) {
    fscanf(file, "%d", &items[i].code);
    getline(&buffer, &bufferSize, file);
    items[i].desc = malloc(bufferSize);
    fscanf(file, "%s", items[i].desc);
    fscanf(file, "%d", &items[i].price);
  }
  free(buffer);

  for (unsigned i = 0; i < size; i++) {
    printf("{%d %s %d}\n", items[i].code, items[i].desc, items[i].price);
  }

  for (unsigned i = 0; i < size; i++) {
    free(items[i].desc);
  }
  free(items);
  fclose(file);

  return 0;
}
