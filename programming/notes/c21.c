#include <stdio.h>
// Να γραφεί συνάρτηση η οποία θα επιστρέφει την διαφορά του ASCII κωδικού ενός
// πεζού λατινικού χαρακτήρα από τον αντίστοιχο κεφαλαίο.
int char_diff(char);

int main(void) {
  printf("%d \n", char_diff('c'));
  return 0;
}

int get_difference(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - ('a' - 'A');
  }
  return 0;
}
