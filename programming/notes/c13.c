#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Να γραφεί πρόγραμμα το οποίο θα διαβάζει λέξη - λέξη ένα αρχείο κειμένου και
// θα τυπώνει την συχνότητα του κάθε κεφαλαίου λατινικού χαρακτήρα (στο συνολικό
// αρχείο) και το σύνολο των χαρακτήρων που δεν ήταν κεφαλαίοι λατινικοί (δεν θα
// υπολογίζονται τα κενά (spaces) και οι αλλαγές γραμμών.
bool calculate_letter_frequency(char const *const file_name,
                                unsigned **const letter_frequency,
                                unsigned *const others) {
  FILE *file_pointer = fopen(file_name, "r");
  if (!file_pointer) {
    return false;
  }

  *letter_frequency = (unsigned *)calloc(26, sizeof(unsigned));
  if (!*letter_frequency) {
    fclose(file_pointer);
    return false;
  }

  char c;
  while ((c = fgetc(file_pointer)) != EOF) {
    if (isalpha(c) && isupper(c)) {
      *(*letter_frequency + c - 'A') += 1;
    } else if (c != '\n' && c != ' ') {
      *others += 1;
    }
  }

  fclose(file_pointer);
  return true;
}

void print_letter_frequency(unsigned const *const frequency) {
  printf("[ ");
  {
    unsigned const *item = frequency;
    while (item < frequency + 26) {
      printf("%u ", *item++);
    }
  }
  printf("]\n");
}

int main(void) {
  unsigned other_letters = 0;
  unsigned *letter_frequency = NULL;
  calculate_letter_frequency("c13_demo.txt", &letter_frequency, &other_letters);
  print_letter_frequency(letter_frequency);
  free(letter_frequency);
  printf("Frequency of other letters: %u\n", other_letters);
  return 0;
}
