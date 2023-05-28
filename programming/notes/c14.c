#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Να γραφεί πρόγραμμα το οποίο θα διαβάζει ένα αρχείο κειμένου χαρακτήρα -
// χαρακτήρα και στο τέλος θα τυπώνει τους χαρακτήρες που υπάρχουν σε αυτό και
// τις συχνότητές τους
void calculate_frequency(char *file_name) {
  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }

  int *frequency = (int *)calloc(256, sizeof(int));
  char ch;
  while ((ch = fgetc(file)) != EOF) {
    frequency[ch]++;
  }
  for (int i = 0; i < 256; i++) {
    if (frequency[i] > 0) {
      printf("'%c' appears %d times\n", i, frequency[i]);
    }
  }
  fclose(file);
  free(frequency);
}

int main() {
  calculate_frequency("c14_demo.txt");
  return 0;
}
