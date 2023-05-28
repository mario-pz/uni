#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Να γραφεί συνάρτηση η οποία θα δέχεται έναν πίνακα χαρακτήρων και στο
// περιεχόμενό του θα μετατρέπει τα πεζά γράμματα σε κεφαλαία και τα κεφαλαία σε
// πεζά (λατινικοί χαρακτήρες). Όλοι οι άλλοι χαρακτήρες θα μένουν αναλλοίωτοι.
void reverse_case(char *);

int main(void) {
  char *temp = calloc(8, 1);
  strcpy(temp, "AAaaBBc");
  reverse_case(temp);
  for (unsigned int i = 0; i < 8; i++) {
    printf("%c ", temp[i]);
  }
  putchar('\n');
  return 0;
}

void reverse_case(char *s) {
  for (unsigned int i = 0; i < strlen(s); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] = s[i] - 32;
    } else if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] = s[i] + 32;
    }
  }
}
